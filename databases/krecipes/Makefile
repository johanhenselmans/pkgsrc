# $NetBSD: Makefile,v 1.29 2012/02/09 21:44:27 sbd Exp $
#

DISTNAME=		krecipes-1.0-beta1
PKGNAME=		krecipes-1.0beta1
PKGREVISION=		15
CATEGORIES=		databases kde
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=krecipes/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://krecipes.sourceforge.net/
COMMENT=		Recipe manager

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
SET_LIBDIR=		yes
USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_TOOLS+=		msgfmt perl

CONFIGURE_ARGS+=	--without-mysql --without-postgresql

.include "../../meta-pkgs/kde3/kde3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
