# $NetBSD: Makefile,v 1.28 2010/05/07 12:02:44 jmmv Exp $

DISTNAME=	osh-20100430
PKGREVISION=	1
CATEGORIES=	shells
MASTER_SITES=	http://v6shell.org/src/

MAINTAINER=	jan+nbsd@v6shell.org
HOMEPAGE=	http://v6shell.org/
COMMENT=	Port of the Sixth Edition UNIX shell
LICENSE=	original-bsd

PKG_DESTDIR_SUPPORT=	user-destdir
PKG_INSTALLATION_TYPES=	overwrite pkgviews

PKG_SHELL=		bin/osh

BUILD_TARGET=	oshall
INSTALL_TARGET=	install-oshall

MAKE_ENV+=	MANDIR=${PREFIX}/${PKGMANDIR}/man1
MAKE_ENV+=	SYSCONFDIR=${PKG_SYSCONFDIR}
MAKE_ENV+=	INSTALL=${TOOLS_PATH.install:Q} BINGRP= MANGRP=

.include "../../mk/bsd.pkg.mk"
