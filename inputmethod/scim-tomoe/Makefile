# $NetBSD: Makefile,v 1.11 2012/02/06 12:40:44 wiz Exp $
#

DISTNAME=		scim-tomoe-0.6.0
PKGREVISION=		11
CATEGORIES=		inputmethod
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=tomoe/}

MAINTAINER=		obache@NetBSD.org
HOMEPAGE=		http://tomoe.sourceforge.jp/
COMMENT=		SCIM IMEngine module for Tomoe
LICENSE=		gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		c c++
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake msgfmt pkg-config intltool
GNU_CONFIGURE=		yes

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../inputmethod/scim/buildlink3.mk"
.include "../../inputmethod/tomoe-gtk/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
