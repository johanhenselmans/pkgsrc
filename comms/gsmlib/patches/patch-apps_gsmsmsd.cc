$NetBSD$

--- apps/gsmsmsd.cc.orig	2011-11-23 15:42:49.000000000 +0000
+++ apps/gsmsmsd.cc
@@ -34,6 +34,7 @@
 #include <stdio.h>
 #include <errno.h>
 #include <stdlib.h>
+#include <string.h>
 #include <signal.h>
 #include <fstream>
 #include <iostream>
