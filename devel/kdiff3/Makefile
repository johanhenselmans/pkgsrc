# $NetBSD$
#

DISTNAME=	kdiff3-0.9.96
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=kdiff3/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://kdiff3.sourceforge.net/
COMMENT=	File and directory diff and merge tool (KDE4)
LICENSE=	gnu-gpl-v2

BUILD_DEPENDS+=	automoc4>=0.9.83:../../devel/automoc4

PKG_DESTDIR_SUPPORT=	user-destdir
USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c c++

USE_TOOLS+=	msgfmt pkg-config

.include "../../meta-pkgs/kde4/kde4.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../x11/kde-baseapps4/buildlink3.mk"
.include "../../x11/kdelibs4/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
