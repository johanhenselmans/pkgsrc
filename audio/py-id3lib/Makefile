# $NetBSD: Makefile,v 1.3 2009/11/29 23:04:15 dholland Exp $
#

DISTNAME=	pyid3lib-0.5.1
PKGNAME=	${PYPKGPREFIX}-id3lib-0.5.1
PKGREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pyid3lib/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://pyid3lib.sourceforge.net/
COMMENT=	Python module for editing ID3v2 tags of MP3 audio files
LICENSE=	gnu-lgpl-v2.1

PKG_DESTDIR_SUPPORT= user-destdir

USE_LANGUAGES=	c c++

.include "../../lang/python/distutils.mk"
.include "../../audio/id3lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
