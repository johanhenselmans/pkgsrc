$NetBSD$

--- omniidl_be/dir.mk.orig	2003-03-23 21:51:59.000000000 +0000
+++ omniidl_be/dir.mk
@@ -6,7 +6,10 @@ ifeq ($(PYTHON),)
 PYTHON = python
 endif
 
-FILES = __init__.py python.py
+FILES = python.py
+ifdef INSTALL_OMNIIDL_BE_INIT
+FILES += __init__.py
+endif
 
 export:: $(FILES)
 	@(dir="$(PYLIBDIR)"; \
