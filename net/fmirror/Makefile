# $NetBSD: Makefile,v 1.3 2008/06/12 02:14:39 joerg Exp $

DISTNAME=		fmirror-0.8.4
CATEGORIES=		net
MASTER_SITES=		# ftp://ftp.guardian.no/pub/free/ftp/fmirror/

MAINTAINER=		he@NetBSD.org
COMMENT=		Mirror program for FTP sites (written in C)

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--datadir=${PREFIX}/share/examples

.include "../../mk/bsd.pkg.mk"
