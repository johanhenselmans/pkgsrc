# $NetBSD: Makefile,v 1.52 2012/02/06 12:40:13 wiz Exp $
#

DISTNAME=	sirius-0.8.0
PKGREVISION=	27
CATEGORIES=	games gnome
MASTER_SITES=	http://sirius.bitvis.nu/files/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://sirius.bitvis.nu/
COMMENT=	Othello game for GNOME2

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		YES
USE_TOOLS+=		gmake intltool msgfmt pkg-config
USE_LIBTOOL=		YES
USE_PKGLOCALEDIR=	YES

.include "../../devel/GConf/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../graphics/libgnomecanvas/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
