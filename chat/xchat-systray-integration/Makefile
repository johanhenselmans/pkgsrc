# $NetBSD: Makefile,v 1.26 2012/02/06 12:39:39 wiz Exp $

DISTNAME=	xchat-systray-integration-2.4.5-src
PKGNAME=	${DISTNAME:S/-src//}
PKGREVISION=	13
CATEGORIES=	chat
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=xchat2-plugins/}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://www.patriziobassi.it/blight/index.php?act=Systray
COMMENT=	Systray icon plugin for XChat

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	xchat>=2.0:../../chat/xchat

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake pkg-config

MAKE_ENV+=	prefix=${PREFIX:Q} SHLIBTOOL=${SHLIBTOOL:Q}

.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
