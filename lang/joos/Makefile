# $NetBSD: Makefile,v 1.13 2009/06/30 00:07:18 joerg Exp $
#

DISTNAME=	joos-0.2
CATEGORIES=	lang java
MASTER_SITES=	# ftp://netbsd.stevens-tech.edu/pub/NetBSD/packages/distfiles/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.brics.dk/~mis/dOvs/index.html
COMMENT=	Java Object Oriented Subset

PKG_DESTDIR_SUPPORT=	user-destdir

MAKE_JOBS_SAFE=		no

USE_JAVA=	run
USE_TOOLS+=	pax

do-install:
	${INSTALL_PROGRAM_DIR} ${DESTDIR}${PREFIX}/joos
	cd ${WRKSRC} && pax -s ,^./.*orig,, -rw . ${DESTDIR}${PREFIX}/joos
	cd ${DESTDIR}${PREFIX}/joos/Bin && ${LN} -s joos.a- joos

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
