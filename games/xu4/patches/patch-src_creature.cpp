$NetBSD$

Add missing header.

--- src/creature.cpp.orig	2005-10-03 06:01:03.000000000 +0000
+++ src/creature.cpp
@@ -21,6 +21,7 @@
 #include "spell.h"  /* FIXME: remove dependence on this */
 #include "tileset.h"
 #include "utils.h"
+#include <string.h>
 
 CreatureMgr *CreatureMgr::instance = NULL;
 
