# $NetBSD: Makefile,v 1.13 2008/03/17 11:25:15 obache Exp $
#

DISTNAME=	ifile-1.3.4
PKGREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	http://www.nongnu.org/ifile/	\
		http://www.nongnu.org/ifile/old/
DIST_SUBDIR=	${PKGNAME_NOREV}

MAINTAINER=	salo@NetBSD.org
HOMEPAGE=	http://www.nongnu.org/ifile/
COMMENT=	Intelligent mail filtering system

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	YES
USE_TOOLS+=	gmake

INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ifile ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/ifile.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
