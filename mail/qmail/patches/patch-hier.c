$NetBSD: patch-hier.c,v 1.1 2011/09/28 06:36:58 joerg Exp $

--- hier.c.orig	1998-06-15 10:53:16.000000000 +0000
+++ hier.c
@@ -37,10 +37,6 @@ void hier()
   d(auto_qmail,"boot",auto_uido,auto_gidq,0755);
   d(auto_qmail,"doc",auto_uido,auto_gidq,0755);
   d(auto_qmail,"man",auto_uido,auto_gidq,0755);
-  d(auto_qmail,"man/cat1",auto_uido,auto_gidq,0755);
-  d(auto_qmail,"man/cat5",auto_uido,auto_gidq,0755);
-  d(auto_qmail,"man/cat7",auto_uido,auto_gidq,0755);
-  d(auto_qmail,"man/cat8",auto_uido,auto_gidq,0755);
   d(auto_qmail,"man/man1",auto_uido,auto_gidq,0755);
   d(auto_qmail,"man/man5",auto_uido,auto_gidq,0755);
   d(auto_qmail,"man/man7",auto_uido,auto_gidq,0755);
@@ -145,108 +141,56 @@ void hier()
   c(auto_qmail,"bin","pinq",auto_uido,auto_gidq,0755);
 
   c(auto_qmail,"man/man5","addresses.5",auto_uido,auto_gidq,0644);
-  c(auto_qmail,"man/cat5","addresses.0",auto_uido,auto_gidq,0644);
   c(auto_qmail,"man/man5","envelopes.5",auto_uido,auto_gidq,0644);
-  c(auto_qmail,"man/cat5","envelopes.0",auto_uido,auto_gidq,0644);
   c(auto_qmail,"man/man5","maildir.5",auto_uido,auto_gidq,0644);
-  c(auto_qmail,"man/cat5","maildir.0",auto_uido,auto_gidq,0644);
   c(auto_qmail,"man/man5","mbox.5",auto_uido,auto_gidq,0644);
-  c(auto_qmail,"man/cat5","mbox.0",auto_uido,auto_gidq,0644);
   c(auto_qmail,"man/man5","dot-qmail.5",auto_uido,auto_gidq,0644);
-  c(auto_qmail,"man/cat5","dot-qmail.0",auto_uido,auto_gidq,0644);
   c(auto_qmail,"man/man5","qmail-control.5",auto_uido,auto_gidq,0644);
-  c(auto_qmail,"man/cat5","qmail-control.0",auto_uido,auto_gidq,0644);
   c(auto_qmail,"man/man5","qmail-header.5",auto_uido,auto_gidq,0644);
-  c(auto_qmail,"man/cat5","qmail-header.0",auto_uido,auto_gidq,0644);
   c(auto_qmail,"man/man5","qmail-log.5",auto_uido,auto_gidq,0644);
-  c(auto_qmail,"man/cat5","qmail-log.0",auto_uido,auto_gidq,0644);
   c(auto_qmail,"man/man5","qmail-users.5",auto_uido,auto_gidq,0644);
-  c(auto_qmail,"man/cat5","qmail-users.0",auto_uido,auto_gidq,0644);
-  c(auto_qmail,"man/man5","tcp-environ.5",auto_uido,auto_gidq,0644);
-  c(auto_qmail,"man/cat5","tcp-environ.0",auto_uido,auto_gidq,0644);
 
   c(auto_qmail,"man/man7","forgeries.7",auto_uido,auto_gidq,0644);
-  c(auto_qmail,"man/cat7","forgeries.0",auto_uido,auto_gidq,0644);
   c(auto_qmail,"man/man7","qmail-limits.7",auto_uido,auto_gidq,0644);
-  c(auto_qmail,"man/cat7","qmail-limits.0",auto_uido,auto_gidq,0644);
   c(auto_qmail,"man/man7","qmail.7",auto_uido,auto_gidq,0644);
-  c(auto_qmail,"man/cat7","qmail.0",auto_uido,auto_gidq,0644);
 
   c(auto_qmail,"man/man1","forward.1",auto_uido,auto_gidq,0644);
-  c(auto_qmail,"man/cat1","forward.0",auto_uido,auto_gidq,0644);
   c(auto_qmail,"man/man1","condredirect.1",auto_uido,auto_gidq,0644);
-  c(auto_qmail,"man/cat1","condredirect.0",auto_uido,auto_gidq,0644);
   c(auto_qmail,"man/man1","bouncesaying.1",auto_uido,auto_gidq,0644);
-  c(auto_qmail,"man/cat1","bouncesaying.0",auto_uido,auto_gidq,0644);
   c(auto_qmail,"man/man1","except.1",auto_uido,auto_gidq,0644);
-  c(auto_qmail,"man/cat1","except.0",auto_uido,auto_gidq,0644);
   c(auto_qmail,"man/man1","maildirmake.1",auto_uido,auto_gidq,0644);
-  c(auto_qmail,"man/cat1","maildirmake.0",auto_uido,auto_gidq,0644);
   c(auto_qmail,"man/man1","maildir2mbox.1",auto_uido,auto_gidq,0644);
-  c(auto_qmail,"man/cat1","maildir2mbox.0",auto_uido,auto_gidq,0644);
   c(auto_qmail,"man/man1","maildirwatch.1",auto_uido,auto_gidq,0644);
-  c(auto_qmail,"man/cat1","maildirwatch.0",auto_uido,auto_gidq,0644);
   c(auto_qmail,"man/man1","mailsubj.1",auto_uido,auto_gidq,0644);
-  c(auto_qmail,"man/cat1","mailsubj.0",auto_uido,auto_gidq,0644);
   c(auto_qmail,"man/man1","qreceipt.1",auto_uido,auto_gidq,0644);
-  c(auto_qmail,"man/cat1","qreceipt.0",auto_uido,auto_gidq,0644);
   c(auto_qmail,"man/man1","qbiff.1",auto_uido,auto_gidq,0644);
-  c(auto_qmail,"man/cat1","qbiff.0",auto_uido,auto_gidq,0644);
   c(auto_qmail,"man/man1","preline.1",auto_uido,auto_gidq,0644);
-  c(auto_qmail,"man/cat1","preline.0",auto_uido,auto_gidq,0644);
   c(auto_qmail,"man/man1","tcp-env.1",auto_uido,auto_gidq,0644);
-  c(auto_qmail,"man/cat1","tcp-env.0",auto_uido,auto_gidq,0644);
 
   c(auto_qmail,"man/man8","qmail-local.8",auto_uido,auto_gidq,0644);
-  c(auto_qmail,"man/cat8","qmail-local.0",auto_uido,auto_gidq,0644);
   c(auto_qmail,"man/man8","qmail-lspawn.8",auto_uido,auto_gidq,0644);
-  c(auto_qmail,"man/cat8","qmail-lspawn.0",auto_uido,auto_gidq,0644);
   c(auto_qmail,"man/man8","qmail-getpw.8",auto_uido,auto_gidq,0644);
-  c(auto_qmail,"man/cat8","qmail-getpw.0",auto_uido,auto_gidq,0644);
   c(auto_qmail,"man/man8","qmail-remote.8",auto_uido,auto_gidq,0644);
-  c(auto_qmail,"man/cat8","qmail-remote.0",auto_uido,auto_gidq,0644);
   c(auto_qmail,"man/man8","qmail-rspawn.8",auto_uido,auto_gidq,0644);
-  c(auto_qmail,"man/cat8","qmail-rspawn.0",auto_uido,auto_gidq,0644);
   c(auto_qmail,"man/man8","qmail-clean.8",auto_uido,auto_gidq,0644);
-  c(auto_qmail,"man/cat8","qmail-clean.0",auto_uido,auto_gidq,0644);
   c(auto_qmail,"man/man8","qmail-send.8",auto_uido,auto_gidq,0644);
-  c(auto_qmail,"man/cat8","qmail-send.0",auto_uido,auto_gidq,0644);
   c(auto_qmail,"man/man8","qmail-start.8",auto_uido,auto_gidq,0644);
-  c(auto_qmail,"man/cat8","qmail-start.0",auto_uido,auto_gidq,0644);
   c(auto_qmail,"man/man8","splogger.8",auto_uido,auto_gidq,0644);
-  c(auto_qmail,"man/cat8","splogger.0",auto_uido,auto_gidq,0644);
   c(auto_qmail,"man/man8","qmail-queue.8",auto_uido,auto_gidq,0644);
-  c(auto_qmail,"man/cat8","qmail-queue.0",auto_uido,auto_gidq,0644);
   c(auto_qmail,"man/man8","qmail-inject.8",auto_uido,auto_gidq,0644);
-  c(auto_qmail,"man/cat8","qmail-inject.0",auto_uido,auto_gidq,0644);
   c(auto_qmail,"man/man8","qmail-showctl.8",auto_uido,auto_gidq,0644);
-  c(auto_qmail,"man/cat8","qmail-showctl.0",auto_uido,auto_gidq,0644);
   c(auto_qmail,"man/man8","qmail-newmrh.8",auto_uido,auto_gidq,0644);
-  c(auto_qmail,"man/cat8","qmail-newmrh.0",auto_uido,auto_gidq,0644);
   c(auto_qmail,"man/man8","qmail-newu.8",auto_uido,auto_gidq,0644);
-  c(auto_qmail,"man/cat8","qmail-newu.0",auto_uido,auto_gidq,0644);
   c(auto_qmail,"man/man8","qmail-pw2u.8",auto_uido,auto_gidq,0644);
-  c(auto_qmail,"man/cat8","qmail-pw2u.0",auto_uido,auto_gidq,0644);
   c(auto_qmail,"man/man8","qmail-qread.8",auto_uido,auto_gidq,0644);
-  c(auto_qmail,"man/cat8","qmail-qread.0",auto_uido,auto_gidq,0644);
   c(auto_qmail,"man/man8","qmail-qstat.8",auto_uido,auto_gidq,0644);
-  c(auto_qmail,"man/cat8","qmail-qstat.0",auto_uido,auto_gidq,0644);
   c(auto_qmail,"man/man8","qmail-tcpok.8",auto_uido,auto_gidq,0644);
-  c(auto_qmail,"man/cat8","qmail-tcpok.0",auto_uido,auto_gidq,0644);
   c(auto_qmail,"man/man8","qmail-tcpto.8",auto_uido,auto_gidq,0644);
-  c(auto_qmail,"man/cat8","qmail-tcpto.0",auto_uido,auto_gidq,0644);
   c(auto_qmail,"man/man8","qmail-pop3d.8",auto_uido,auto_gidq,0644);
-  c(auto_qmail,"man/cat8","qmail-pop3d.0",auto_uido,auto_gidq,0644);
   c(auto_qmail,"man/man8","qmail-popup.8",auto_uido,auto_gidq,0644);
-  c(auto_qmail,"man/cat8","qmail-popup.0",auto_uido,auto_gidq,0644);
   c(auto_qmail,"man/man8","qmail-qmqpc.8",auto_uido,auto_gidq,0644);
-  c(auto_qmail,"man/cat8","qmail-qmqpc.0",auto_uido,auto_gidq,0644);
   c(auto_qmail,"man/man8","qmail-qmqpd.8",auto_uido,auto_gidq,0644);
-  c(auto_qmail,"man/cat8","qmail-qmqpd.0",auto_uido,auto_gidq,0644);
   c(auto_qmail,"man/man8","qmail-qmtpd.8",auto_uido,auto_gidq,0644);
-  c(auto_qmail,"man/cat8","qmail-qmtpd.0",auto_uido,auto_gidq,0644);
   c(auto_qmail,"man/man8","qmail-smtpd.8",auto_uido,auto_gidq,0644);
-  c(auto_qmail,"man/cat8","qmail-smtpd.0",auto_uido,auto_gidq,0644);
   c(auto_qmail,"man/man8","qmail-command.8",auto_uido,auto_gidq,0644);
-  c(auto_qmail,"man/cat8","qmail-command.0",auto_uido,auto_gidq,0644);
 }
