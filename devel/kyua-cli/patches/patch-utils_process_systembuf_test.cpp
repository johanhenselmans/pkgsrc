$NetBSD$

--- utils/process/systembuf_test.cpp.orig	2012-01-16 17:31:50.000000000 +0000
+++ utils/process/systembuf_test.cpp
@@ -29,6 +29,9 @@
 #include "utils/process/systembuf.hpp"
 
 extern "C" {
+#ifdef __DragonFly__
+#include <sys/stat.h>
+#endif
 #include <fcntl.h>
 #include <unistd.h>
 }
