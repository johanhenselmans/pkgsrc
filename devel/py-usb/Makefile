# $NetBSD: Makefile,v 1.3 2009/10/11 08:32:50 wiz Exp $

VERSION=	0.4.2
DISTNAME=	pyusb-${VERSION}
PKGNAME=	${PYPKGPREFIX}-usb-${VERSION}
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pyusb/}

MAINTAINER=	wiml@hhhh.org
HOMEPAGE=	http://pyusb.berlios.de/
COMMENT=	Python interface to USB via libusb

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../devel/libusb/buildlink3.mk"
.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
