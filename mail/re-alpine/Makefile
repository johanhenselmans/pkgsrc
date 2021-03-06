# $NetBSD: Makefile,v 1.4 2012/02/10 08:44:25 cheusov Exp $
#

DISTNAME=	re-alpine-2.01
PKGREVISION=	2
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=re-alpine/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	reed@reedmedia.net
HOMEPAGE=	http://sourceforge.net/projects/re-alpine/
COMMENT=	Console-based mail and news client
LICENSE=	apache-2.0

CONFLICTS=	alpine-[0-9]*

PKG_DESTDIR_SUPPORT=	user-destdir

.include "options.mk"

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+= --with-ssl-dir=${SSLBASE}
CONFIGURE_ARGS+= --with-ssl-certs-dir=${SSLCERTS:Q}
CONFIGURE_ARGS+= --with-ssl-include-dir=${SSLBASE}/include
CONFIGURE_ARGS+= --with-ssl-lib-dir=${SSLBASE}/lib
CONFIGURE_ARGS+= --with-system-pinerc=${PKG_SYSCONFDIR}/pine.conf
CONFIGURE_ARGS+= --with-system-fixed-pinerc=${PKG_SYSCONFDIR}/pine.conf.fixed

USE_LIBTOOL=	yes

MAKE_JOBS_SAFE=         no
INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

.if ${OPSYS} == "NetBSD" && empty(OS_VERSION:M4.99.*) && empty(OS_VERSION:M[5-9]*)
CONFIGURE_ARGS+= --without-pthread
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/alpine/alpine ${DESTDIR}${PREFIX}/bin/alpine
	${INSTALL_MAN} ${WRKSRC}/doc/alpine.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/alpine.1

.include "../../mk/terminfo.buildlink3.mk"
.include "../../mk/pam.buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
