# $NetBSD: Makefile,v 1.2 2008/04/06 13:17:22 heinz Exp $

DISTNAME=	zonetab-0
CATEGORIES=	time
DISTFILES=	# empty

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	zone.tab file

PKG_DESTDIR_SUPPORT=	user-destdir

NO_BUILD=	yes

# install path is hardwired
ONLY_FOR_PLATFORM=	NetBSD-*-*

ZTDIR=	${PREFIX}/share/examples/zoneinfo

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${ZTDIR}
	${INSTALL_DATA} ${FILESDIR}/zone.tab ${DESTDIR}${ZTDIR}

.include "../../mk/bsd.pkg.mk"
