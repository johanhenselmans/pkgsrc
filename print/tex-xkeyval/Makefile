# $NetBSD: Makefile,v 1.3 2010/04/10 16:07:14 minskim Exp $

DISTNAME=	xkeyval
PKGNAME=	tex-${DISTNAME}-2.6a
TEXLIVE_REV=	15878

MAINTAINER=	jmmv@NetBSD.org
COMMENT=	Macros for setting keys and class or package options

CONFLICTS+=	teTeX-texmf<=3.0nb17
DEPENDS+=	tex-tools-[0-9]*:../../print/tex-tools

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
