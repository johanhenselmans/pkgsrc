# $NetBSD: Makefile,v 1.9 2008/03/03 20:17:12 jlam Exp $
#

DISTNAME=	freefonts-0.10
PKGREVISION=	2
CATEGORIES=	fonts
MASTER_SITES=	${MASTER_SITE_SUNSITE:=X11/fonts/} \
		ftp://ftp.gimp.org/pub/gimp/fonts/

MAINTAINER=	reed@reedmedia.net
COMMENT=	Collection of 79 freely available fonts

PKG_DESTDIR_SUPPORT=	destdir

EXTRACT_ONLY=	# empty
NO_CONFIGURE=	yes
NO_BUILD=	yes

USE_X11BASE=	yes
USE_TOOLS+=	gtar gzip
FONTS_DIRS.x11=	${PREFIX}/lib/X11/fonts/freefont
REQD_DIRS=	${PREFIX}/lib/X11/fonts/freefont

INSTALLATION_DIRS=	lib/X11/fonts

do-install:
	${GTAR} Cxzf ${DESTDIR}${PREFIX}/lib/X11/fonts \
		${_DISTDIR}/${DISTNAME}${EXTRACT_SUFX}
	${CHMOD} ${SHAREMODE} ${DESTDIR}${PREFIX}/lib/X11/fonts/freefont/*
	${CHOWN} ${SHAREOWN}:${SHAREGRP} \
		${DESTDIR}${PREFIX}/lib/X11/fonts/freefont/*

.include "../../mk/bsd.pkg.mk"
