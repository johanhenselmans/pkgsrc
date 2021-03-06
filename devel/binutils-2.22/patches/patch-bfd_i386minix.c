$NetBSD$

--- bfd/i386minix.c.orig	Fri Jul  6 01:31:01 2012
+++ bfd/i386minix.c
@@ -0,0 +1,325 @@
+/* BFD back-end for i386 minix a.out binaries.
+   Copyright 1990, 1991, 1992, 1994, 1996, 1997, 2001, 2002, 2003
+   Free Software Foundation, Inc.
+
+This file is part of BFD, the Binary File Descriptor library.
+
+This program is free software; you can redistribute it and/or modify
+it under the terms of the GNU General Public License as published by
+the Free Software Foundation; either version 2 of the License, or
+(at your option) any later version.
+
+This program is distributed in the hope that it will be useful,
+but WITHOUT ANY WARRANTY; without even the implied warranty of
+MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
+GNU General Public License for more details.
+
+You should have received a copy of the GNU General Public License
+along with this program; if not, write to the Free Software
+Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
+
+/***************/
+/* EXEC FORMAT */
+/***************/
+#include <a.out.h>
+
+#define external_exec exec
+#define EXEC_BYTES_SIZE sizeof( struct exec )
+
+#define OMAGIC 0407		/* Object file or impure executable.  */
+#define NMAGIC 0410		/* Code indicating pure executable.  */
+#define ZMAGIC 0x0301	/* Code indicating demand-paged executable.  */
+#define BMAGIC 0415		/* Used by a b.out object.  */
+
+#ifndef QMAGIC
+#define QMAGIC 0314
+#endif
+# ifndef N_BADMAG
+#  define N_BADMAG(x)	  (N_MAGIC(x) != OMAGIC		\
+			&& N_MAGIC(x) != NMAGIC		\
+  			&& N_MAGIC(x) != ZMAGIC \
+		        && N_MAGIC(x) != QMAGIC)
+# endif /* N_BADMAG */
+
+#define N_HEADER_IN_TEXT(x) 0
+
+#define N_TXTOFF(x) EXEC_BYTES_SIZE
+#define N_TXTADDR(x) 0
+
+#define N_TXTSIZE(x) ((x).a_text)
+#ifdef SUPPORT_SEP
+#define MINIX_IS_SEP(x) 0 /*-> gcv.c HCLICK STUFF*/
+#define N_DATADDR(x) (MINIX_IS_SEP(x) ? align((x).a_text,HCLICK) : (x).a_text )
+#else
+#define N_DATADDR(x) ((x).a_text)
+#endif
+
+/* Are these values correct? */
+#define TARGET_PAGE_SIZE 1
+#define SEGMENT_SIZE 1
+
+#define DEFAULT_STACK 5 * 1024 * 1024 /* 5 MB stack */
+
+#define DEFAULT_ARCH bfd_arch_i386
+
+/* Do not "beautify" the CONCAT* macro args.  Traditional C will not
+   remove whitespace added here, and thus will fail to concatenate
+   the tokens.  */
+#define MY(OP) CONCAT2 (i386minix_,OP)
+#define NAME(a,b) i386minix_32_##b
+#define TARGETNAME "a.out-i386-minix"
+#define NO_WRITE_HEADER_KLUDGE 1
+
+#define ARCH_SIZE 32
+
+#include "bfd.h"
+#include "sysdep.h"
+/*#include "libbfd.h"*/
+#include "aout/aout64.h"
+#include "libaout.h"
+
+
+#define i386minix_32_get_section_contents _bfd_generic_get_section_contents
+
+#define SET_ARCH_MACH(abfd, exec) \
+	bfd_set_arch_mach(abfd, DEFAULT_ARCH, 0)
+
+static bfd_boolean i386minix_write_object_contents PARAMS ((bfd *));
+#define MY_write_object_contents i386minix_write_object_contents
+
+static int  MY(swap_exec_header_in)  PARAMS ((bfd *, struct external_exec *, struct internal_exec *));
+static void MY(swap_exec_header_out) PARAMS ((bfd *, struct internal_exec *, struct external_exec *));
+
+#define NAME_swap_exec_header_in	MY(swap_exec_header_in)
+#define NAME_swap_exec_header_out	MY(swap_exec_header_out)
+
+#define MY_object_p MY(object_p)
+static const bfd_target * MY(object_p) (bfd *);
+
+
+static bfd_boolean MY (set_sizes) PARAMS ((bfd *));
+
+#define MY_backend_data &MY(backend_data)
+static const struct aout_backend_data MY(backend_data) = {
+  0,				/* zmagic contiguous */
+  1,				/* text incl header */
+  0,				/* entry is text address */
+  0,				/* exec_hdr_flags */
+  0,				/* text vma? */
+  MY(set_sizes),
+  1,				/* exec header not counted */
+  0,				/* add_dynamic_symbols */
+  0,				/* add_one_symbol */
+  0,				/* link_dynamic_object */
+  0,				/* write_dynamic_symbol */
+  0,				/* check_dynamic_reloc */
+  0				/* finish_dynamic_link */
+};
+
+#include "aoutx.h"
+
+#include "aout-target.h"
+
+/****************/
+/* WRITE HEADER */
+/****************/
+static void
+MY(swap_exec_header_out) (abfd, execp, bytes)
+     bfd *abfd;
+     struct internal_exec *execp;
+     struct external_exec *bytes;
+{
+  int total;
+  int stack;
+  
+  /* Now fill in fields in the raw data, from the fields in the exec struct.  */
+  H_PUT_16 (abfd, N_MAGIC(*execp), bytes->a_magic);
+  
+  bytes->a_flags = 0;
+  if ( bytes->a_syms )
+  	bytes->a_flags |= A_NSYM;
+
+  bytes->a_cpu = A_I80386;
+  
+  bytes->a_hdrlen = EXEC_BYTES_SIZE;
+  
+  bytes->a_unused = 0;
+  bytes->a_version = 0;
+  
+  PUT_WORD (abfd, execp->a_text  , &bytes->a_text);
+  PUT_WORD (abfd, execp->a_data  , &bytes->a_data);
+  PUT_WORD (abfd, execp->a_bss   , &bytes->a_bss);
+  PUT_WORD (abfd, execp->a_entry , &bytes->a_entry);
+  
+  stack = DEFAULT_STACK;
+  total = execp->a_data + execp->a_bss + stack;
+#if 0
+	if ( MINIX_IS_SEP( abfd ) )
+		bytes->a_flags |= A_SEP;
+	else
+#endif
+		total += execp->a_text;
+		
+  PUT_WORD (abfd, total          , &bytes->a_total);		
+  PUT_WORD (abfd, execp->a_syms  , &bytes->a_syms);
+  PUT_WORD (abfd, execp->a_trsize, &bytes->a_trsize);
+  PUT_WORD (abfd, execp->a_drsize, &bytes->a_drsize);
+  
+  bytes->a_tbase = bytes->a_dbase = 0;
+}
+
+#define i386minix_32_swap_exec_header_out MY(swap_exec_header_out)
+/* WRITE_HEADERS calls NAME(aout,swap_exec_header_out)
+   which I need to overwrite. Unfortunately aoutx.h doesn't have a
+   NAME_swap_exec_header_out like it does for -_in.
+   So I have to redefine the outcome of NAME(aout,swap_exec_header_out) to 
+   my own function before using WRITE_HEADERS */
+
+/* Set the machine type correctly.  */
+static bfd_boolean
+i386minix_write_object_contents (abfd)
+     bfd *abfd;
+{
+  struct external_exec exec_bytes;
+  struct internal_exec *execp = exec_hdr (abfd);
+
+  N_SET_MACHTYPE (*execp, M_386);
+  
+  obj_reloc_entry_size (abfd) = RELOC_STD_SIZE;
+
+  WRITE_HEADERS (abfd, execp);
+
+  return TRUE;
+}
+/* undo renaming to be able to include aoutx.h */
+#undef i386minix_32_swap_exec_header_out
+
+/***************/
+/* READ HEADER */
+/***************/
+/* define if aoutx.h is included: */
+/* UNTRUE: but including it generates a conflict with swap_exe_header_out, so don't include it */
+
+/* return -1 if header is wrong
+ * otherwise return the bytes left to read */
+static int
+MY(swap_exec_header_in) (abfd, bytes, execp)
+     bfd *abfd;
+     struct external_exec *bytes;
+     struct internal_exec *execp;
+{
+  /* The internal_exec structure has some fields that are unused in this
+     configuration (IE for i960), so ensure that all such uninitialized
+     fields are zero'd out.  There are places where two of these structs
+     are memcmp'd, and thus the contents do matter.  */
+  memset ((PTR) execp, 0, sizeof (struct internal_exec));
+  /* Now fill in fields in the execp, from the bytes in the raw data.  */
+  
+  /*fill a_info*/
+  N_SET_MAGIC(*execp, H_GET_16 (abfd, bytes->a_magic));
+  N_SET_MACHTYPE(*execp, M_386);
+  N_SET_FLAGS(*execp, 0);
+  
+  /*check integrity*/
+  if ( N_BADMAG( *execp ) )
+  	return -1;
+  
+  if ( bytes->a_cpu != A_I80386 )
+  	return -1;
+  	
+  if ( bytes->a_hdrlen < A_MINHDR )
+  	return -1;
+  	
+#if 0
+	if ( bytes->a_flags & A_SEP )
+		dosomething();
+#endif
+
+  /*fill the rest*/
+  execp->a_text   = GET_WORD (abfd, &bytes->a_text);
+  execp->a_data   = GET_WORD (abfd, &bytes->a_data);
+  execp->a_bss    = GET_WORD (abfd, &bytes->a_bss);
+  execp->a_syms   = GET_WORD (abfd, &bytes->a_syms);
+  execp->a_entry  = GET_WORD (abfd, &bytes->a_entry);
+  
+  if ( bytes->a_hdrlen < A_MINHDR + 2 * sizeof(long) )
+  	return bytes->a_hdrlen - A_MINHDR;
+
+  if (bfd_bread (&bytes->a_trsize, 2 * sizeof(long), abfd) != 2 * sizeof(long))
+  	return -1;
+    
+  execp->a_trsize = GET_WORD (abfd, &bytes->a_trsize);
+  execp->a_drsize = GET_WORD (abfd, &bytes->a_drsize);
+
+  bfd_seek (abfd, -2 * sizeof(long), SEEK_CUR);  
+  
+  /*store other fields of external_exec?*/
+  return bytes->a_hdrlen - A_MINHDR;
+}
+
+static const bfd_target *
+MY(object_p) (abfd)
+     bfd *abfd;
+{
+  struct external_exec exec_bytes;	/* Raw exec header from file */
+  struct internal_exec exec;		/* Cleaned-up exec header */
+  const bfd_target *target;
+  int left;
+  bfd_size_type amt = A_MINHDR;
+  
+  if (bfd_bread ((PTR) &exec_bytes, amt, abfd) != amt)
+    {
+      if (bfd_get_error () != bfd_error_system_call)
+	bfd_set_error (bfd_error_wrong_format);
+	
+      return 0;
+    }
+
+  /* let MY(swap_exec_header_in) check the header */
+  if ( (left = MY(swap_exec_header_in) (abfd, &exec_bytes, &exec)) == -1 )
+  {
+  	/* incorrect header */
+  	return 0;
+  }
+
+  /* skip rest of header */
+  if ( bfd_seek( abfd, left, SEEK_CUR ) )
+  	return 0;
+  
+  target = NAME(aout,some_aout_object_p) (abfd, &exec, MY(callback));
+
+  int adjust = (A_MINHDR + left) - EXEC_BYTES_SIZE;
+  
+  /* adjust file positions with the bytes left to be read from the header */
+  obj_textsec (abfd)->filepos += adjust;
+  obj_datasec (abfd)->filepos += adjust;
+  
+  obj_textsec (abfd)->rel_filepos += adjust;
+  obj_datasec (abfd)->rel_filepos += adjust;
+  
+  obj_sym_filepos (abfd) += adjust;
+  obj_str_filepos (abfd) += adjust;
+
+  adata(abfd).exec_bytes_size = A_MINHDR + left;
+      
+#ifdef ENTRY_CAN_BE_ZERO
+  /* The NEWSOS3 entry-point is/was 0, which (amongst other lossage)
+   * means that it isn't obvious if EXEC_P should be set.
+   * All of the following must be true for an executable:
+   * There must be no relocations, the bfd can be neither an
+   * archive nor an archive element, and the file must be executable.  */
+
+  if (exec.a_trsize + exec.a_drsize == 0
+      && bfd_get_format(abfd) == bfd_object && abfd->my_archive == NULL)
+    {
+      struct stat buf;
+#ifndef S_IXUSR
+#define S_IXUSR 0100	/* Execute by owner.  */
+#endif
+      if (stat(abfd->filename, &buf) == 0 && (buf.st_mode & S_IXUSR))
+	abfd->flags |= EXEC_P;
+    }
+#endif /* ENTRY_CAN_BE_ZERO */
+
+  return target;
+}
