# $NetBSD: Makefile,v 1.19 2012/02/06 12:41:16 wiz Exp $

DISTNAME=	monsoon-0.20
PKGREVISION=	15
CATEGORIES=	net
MASTER_SITES=	http://www.monsoon-project.org/jaws/data/files/

MAINTAINER=	kefren@NetBSD.org
HOMEPAGE=	http://www.monsoon-project.org/
COMMENT=	Open source GTK+ bittorrent client

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
MAKE_JOBS_SAFE=	no
USE_TOOLS+=	gmake gtar intltool perl pkg-config msgfmt
EXTRACT_USING=	gtar

.include "../../lang/mono/buildlink3.mk"
.include "../../net/mono-nat/buildlink3.mk"
.include "../../net/monotorrent/buildlink3.mk"
.include "../../sysutils/ndesk-dbus/buildlink3.mk"
.include "../../sysutils/ndesk-dbus-glib/buildlink3.mk"
.include "../../x11/gnome-sharp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
