$NetBSD$

Fix for:
* An integer overflow leading to a heap-based buffer overflow in the
Open() function in modules/demux/tta.c (CVE-2008-3732).

--- modules/demux/tta.c.orig	2008-07-08 21:59:23.000000000 +0100
+++ modules/demux/tta.c	2008-09-12 11:16:11.000000000 +0100
@@ -60,10 +60,10 @@
     es_out_id_t *p_es;
 
     /* */
-    int      i_totalframes;
-    int      i_currentframe;
+    uint32_t i_totalframes;
+    uint32_t i_currentframe;
     uint32_t *pi_seektable;
-    int      i_datalength;
+    uint32_t i_datalength;
     int      i_framelength;
 
     /* */
@@ -81,10 +81,11 @@
     es_format_t fmt;
     uint8_t     *p_peek;
     uint8_t     p_header[22];
-    uint8_t     *p_seektable;
-    int         i_seektable_size = 0, i;
+    uint8_t     *p_fullheader;
+    int         i_seektable_size = 0;
     //char        psz_info[4096];
     //module_t    *p_id3;
+    uint32_t    i;
 
     if( stream_Peek( p_demux->s, &p_peek, 4 ) < 4 )
         return VLC_EGENERIC;
@@ -94,7 +95,7 @@
         if( !p_demux->b_force ) return VLC_EGENERIC;
 
         /* User forced */
-        msg_Err( p_demux, "this doesn't look like a flac stream, "
+        msg_Err( p_demux, "this doesn't look like a true-audio stream, "
                  "continuing anyway" );
     }
 
@@ -106,11 +107,22 @@
     p_demux->pf_control = Control;
     p_demux->p_sys = p_sys = malloc( sizeof( demux_sys_t ) );
     
+    if( !p_sys )
+        return VLC_ENOMEM;
+
+    p_sys->pi_seektable = NULL;
+
     /* Read the metadata */
     es_format_Init( &fmt, AUDIO_ES, VLC_FOURCC( 'T', 'T', 'A', '1' ) );
     fmt.audio.i_channels = GetWLE( &p_header[6] );
     fmt.audio.i_bitspersample = GetWLE( &p_header[8] );
     fmt.audio.i_rate = GetDWLE( &p_header[10] );
+    if( fmt.audio.i_rate == 0 || /* Avoid divide by 0 */
+        fmt.audio.i_rate > ( 1 << 20 ) /* Avoid i_framelength overflow */ )
+    {
+        msg_Warn( p_demux, "Wrong sample rate" );
+        goto error;
+    }
 
     p_sys->i_datalength = GetDWLE( &p_header[14] );
     p_sys->i_framelength = TTA_FRAMETIME * fmt.audio.i_rate;
@@ -118,25 +130,36 @@
     p_sys->i_totalframes = p_sys->i_datalength / p_sys->i_framelength + 
                           ((p_sys->i_datalength % p_sys->i_framelength) ? 1 : 0);
     p_sys->i_currentframe = 0;
+    if( p_sys->i_totalframes > (1 << 29))
+        goto error;
 
     i_seektable_size = sizeof(uint32_t)*p_sys->i_totalframes;
-    p_seektable = (uint8_t *)malloc( i_seektable_size );
-    stream_Read( p_demux->s, p_seektable, i_seektable_size );
-    p_sys->pi_seektable = (uint32_t *)malloc(i_seektable_size);
 
+    /* Store the header and Seektable for avcodec */
+    fmt.i_extra = 22 + i_seektable_size + 4;
+    fmt.p_extra = p_fullheader = malloc( fmt.i_extra );
+    if( !p_fullheader )
+        goto error;
+
+    memcpy( p_fullheader, p_header, 22 );
+    p_fullheader += 22;
+    if( stream_Read( p_demux->s, p_fullheader, i_seektable_size )
+             != i_seektable_size )
+        goto error;
+
+    p_sys->pi_seektable = calloc( p_sys->i_totalframes, sizeof(uint32_t) );
+    if( !p_sys->pi_seektable )
+        goto error;
     for( i = 0; i < p_sys->i_totalframes; i++ )
-        p_sys->pi_seektable[i] = GetDWLE( &p_seektable[i*4] );
-
-    stream_Read( p_demux->s, NULL, 4 ); /* CRC */
+    {
+        p_sys->pi_seektable[i] = GetDWLE( p_fullheader );
+        p_fullheader += 4;
+    }
 
-    /* Store the header and Seektable for avcodec */
-    fmt.i_extra = 22 + (p_sys->i_totalframes * 4) + 4;
-    fmt.p_extra = malloc( fmt.i_extra );
-    memcpy( fmt.p_extra, p_header, 22 );
-    memcpy( fmt.p_extra+22, p_seektable, fmt.i_extra -22 );
+    stream_Read( p_demux->s, p_fullheader, 4 ); /* CRC */
+    p_fullheader += 4;
 
     p_sys->p_es = es_out_Add( p_demux->out, &fmt );
-    free( p_seektable );
     p_sys->i_start = stream_Tell( p_demux->s );
     
 #if 0
@@ -152,6 +175,10 @@
         p_sys->p_meta = vlc_meta_New();
 #endif
     return VLC_SUCCESS;
+error:
+    es_format_Clean( &fmt );
+    Close( p_this );
+    return VLC_EGENERIC;
 }
 
 /*****************************************************************************
@@ -162,6 +189,7 @@
     demux_t        *p_demux = (demux_t*)p_this;
     demux_sys_t    *p_sys = p_demux->p_sys;
 
+    free( p_sys->pi_seektable );
     free( p_sys );
 }
 
@@ -221,7 +249,7 @@
             if( i64 > 0 )
             {
                 int64_t tmp = 0;
-                int     i;
+                uint32_t i;
                 for( i=0; i < p_sys->i_totalframes && tmp+p_sys->pi_seektable[i] < i64; i++)
                 {
                     tmp += p_sys->pi_seektable[i];
