# $NetBSD: Makefile,v 1.10 2006/10/22 21:20:54 rillig Exp $

DISTNAME=	fbm-1.2
CATEGORIES=	graphics converters
MASTER_SITES=	${MASTER_SITE_SUNSITE:=apps/graphics/convert/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Fuzzy Pixmap Manipulation utilities

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}
INSTALL_MAKE_FLAGS+=	BIN=${DESTDIR}${PREFIX}/bin/ \
			MAN=${DESTDIR}${PREFIX}/${PKGMANDIR}/manl/
INSTALLATION_DIRS+=	bin ${PKGMANDIR}/manl

.include "../../mk/bsd.pkg.mk"
