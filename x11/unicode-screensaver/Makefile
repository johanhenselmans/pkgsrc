# $NetBSD: Makefile,v 1.1.1.1 2010/09/03 22:50:09 wiz Exp $
#

DISTNAME=	unicode-screensaver-0.3
PKGREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	http://www.joachim-breitner.de/archive/unicode-screensaver/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.joachim-breitner.de/projects#unicode-screensaver
COMMENT=	Screensaver that repeatedly randomly picks an unicode character

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

post-install:
	${MV} ${DESTDIR}${PREFIX}/${PKGMANDIR}/man6/unicode.6x \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man6/unicode.6

.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXmu/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/libXft/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
