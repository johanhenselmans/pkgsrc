$NetBSD$

--- libltdl/m4/ltdl.m4.orig	Thu Apr 26 22:45:23 2012
+++ libltdl/m4/ltdl.m4
@@ -493,6 +493,9 @@ AC_CACHE_CHECK([whether deplibs are loaded by dlopen],
   netbsd*)
     lt_cv_sys_dlopen_deplibs=yes
     ;;
+  minix*)
+    lt_cv_sys_dlopen_deplibs=yes
+    ;; 
   openbsd*)
     lt_cv_sys_dlopen_deplibs=yes
     ;;
