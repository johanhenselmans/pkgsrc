# $NetBSD: Makefile,v 1.28 2009/12/03 13:06:53 asau Exp $
#

DISTNAME=	blas
PKGNAME=	blas-1.1
PKGREVISION=	2
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_NETLIB:=blas/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://www.netlib.org/blas/
COMMENT=	Basic Linear Algebra Subprograms (Fortran)

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

DIST_SUBDIR=		${PKGNAME_NOREV}
WRKSRC=			${WRKDIR}/BLAS
USE_LANGUAGES=		c fortran77
USE_LIBTOOL=		yes

# Pass along the major and minor of the version number as the major and
# minor of the shared library to be built.
#
MAKE_ENV+=	SHLIB_MAJOR=${PKGNAME_NOREV:S/${PKGBASE}-//:C/[.].*$//}
MAKE_ENV+=	SHLIB_MINOR=${PKGNAME_NOREV:S/${PKGBASE}-//:C/^.*[.]//}

post-extract:
	cp -f ${FILESDIR}/Makefile.blas ${WRKSRC}/Makefile

.include "../../mk/bsd.pkg.mk"
