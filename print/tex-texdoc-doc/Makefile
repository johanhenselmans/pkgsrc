# $NetBSD$

DISTNAME=	texdoc.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-2011
TEXLIVE_REV=	24354

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Documentation for tex-texdoc
LICENSE=	gnu-gpl-v3

CONFLICTS+=	texlive-tetex<2011nb1

TEX_TEXMF_DIRS+=	${PREFIX}/share/texmf

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
