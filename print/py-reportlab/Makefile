# $NetBSD: Makefile,v 1.43 2012/02/04 04:41:56 obache Exp $

DISTNAME=	reportlab-2.5
DISTFILES=	${DEFAULT_DISTFILES} pfbfer.zip
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	print python
MASTER_SITES=	http://www.reportlab.com/ftp/
SITES.pfbfer.zip=	http://www.reportlab.com/ftp/fonts/

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	http://www.reportlab.com/
COMMENT=	Powerful PDF-generating toolkit for Python
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-expat-[0-9]*:../../textproc/py-expat
DEPENDS+=	${PYPKGPREFIX}-imaging-[0-9]*:../../graphics/py-imaging

PKG_DESTDIR_SUPPORT=	user-destdir

EXTRACT_DIR.pfbfer.zip=	${WRKSRC}/src/reportlab/fonts

do-test:
	${RUN}cd ${WRKSRC};${PYTHONBIN} setup.py tests

.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/libart/buildlink3.mk"
.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
