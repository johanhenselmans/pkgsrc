# $NetBSD: Makefile,v 1.25 2008/11/10 17:21:33 wiz Exp $

DISTNAME=		xmix-2.1
PKGREVISION=		3
CATEGORIES=		audio
MASTER_SITES=		${MASTER_SITE_SUNSITE:=apps/sound/mixers/}

PATCH_SITES=		${MASTER_SITES}
PATCHFILES=		xmix-2.1.mixers.patch

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		Mixer for X Window System

PKG_DESTDIR_SUPPORT=	user-destdir

NOT_FOR_PLATFORM=	Interix-*-*

WRKSRC=			${WRKDIR}/xmix
USE_IMAKE=		yes
INSTALLATION_DIRS=	lib/X11/app-defaults

pre-configure:
	${CP} ${WRKSRC}/xmix.1 ${WRKSRC}/xmix.man

pre-install:
	${INSTALL_DATA} ${WRKSRC}/XMix ${DESTDIR}${PREFIX}/lib/X11/app-defaults

.include "../../x11/libXaw/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
