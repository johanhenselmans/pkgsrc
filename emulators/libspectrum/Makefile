# $NetBSD: Makefile,v 1.28 2012/02/06 12:40:06 wiz Exp $

DISTNAME=	libspectrum-1.0.0
PKGREVISION=	4
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=fuse-emulator/}

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://fuse-emulator.sourceforge.net/libspectrum.php
COMMENT=	ZX Spectrum emulator file format library
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=		gmake perl pkg-config
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

DOCDIR=		${PREFIX}/share/doc/libspectrum
INSTALLATION_DIRS=	${DOCDIR}

post-install:
	${INSTALL_DATA} ${WRKSRC}/doc/libspectrum.txt ${DESTDIR}${DOCDIR}

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../audio/libaudiofile/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/libgcrypt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
