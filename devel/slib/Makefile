# $NetBSD: Makefile,v 1.32 2009/09/09 22:56:13 wiz Exp $

DISTNAME=	slib-3b3
#
# Convert the version number as follows 2d2 -> 2.4.2, where the d is
# changed to a 4, representing the 4th letter.
# Thus, 3a1 -> 3.1.1
#
# Also update guile-slib
#
PKGNAME=	slib-3.2.3
CATEGORIES=	devel
MASTER_SITES=	http://swissnet.ai.mit.edu/ftpdir/scm/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://swissnet.ai.mit.edu/~jaffer/SLIB.html
COMMENT=	Portable Scheme library of compatibility and utility functions

PKG_DESTDIR_SUPPORT=	user-destdir

NO_CONFIGURE=	yes
NO_BUILD=	yes

SLIBDIR=	${PREFIX}/share/slib
DOCDIR=		${PREFIX}/share/doc/slib
INFO_FILES=	yes

INSTALLATION_DIRS=	${PKGINFODIR}

SUBST_CLASSES+=		scmpath
SUBST_STAGE.scmpath=	post-patch
SUBST_FILES.scmpath=	guile.init
SUBST_SED.scmpath=	-e "s|/usr/share/slib|${PREFIX}/share/slib|"

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${SLIBDIR}
	cd ${WRKSRC}; ${INSTALL_DATA} *.scm *.init ${DESTDIR}${SLIBDIR}
	${INSTALL_DATA_DIR} ${DESTDIR}${DOCDIR}
	cd ${WRKSRC}; ${INSTALL_DATA} README FAQ ${DESTDIR}${DOCDIR}
	cd ${WRKSRC}; for f in slib.info slib.info-[0-9]*; do		\
		${TEST} ! -f "$$f" ||					\
		${INSTALL_DATA} "$$f" ${DESTDIR}${PREFIX}/${PKGINFODIR};\
	done

.include "../../mk/bsd.pkg.mk"
