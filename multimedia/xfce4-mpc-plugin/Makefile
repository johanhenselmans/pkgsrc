# $NetBSD: Makefile,v 1.11 2012/02/06 12:41:09 wiz Exp $

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../meta-pkgs/xfce4/Makefile.common"

XFCE4_VERSION=	0.3.2

DISTNAME=	xfce4-mpc-plugin-${XFCE4_VERSION}
PKGREVISION=	9
CATEGORIES=	multimedia
MASTER_SITES=	http://goodies.xfce.org/releases/xfce4-mpc-plugin/
EXTRACT_SUFX=	.tar.gz
COMMENT=	Xfce Music Player Client plugin

.include "../../x11/xfce4-panel/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
