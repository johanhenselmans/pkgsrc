# $NetBSD: Makefile,v 1.34 2008/06/12 02:14:40 joerg Exp $

DISTNAME=		pchar-1.5
PKGREVISION=		2
CATEGORIES=		net
MASTER_SITES=		http://www.kitchenlab.org/www/bmah/Software/pchar/

MAINTAINER=		soren@NetBSD.org
HOMEPAGE=		http://www.kitchenlab.org/www/bmah/Software/pchar/
COMMENT=		Tool for measuring Internet path characteristics

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_LANGUAGES=		c c++

PKG_OPTIONS_VAR=	PKG_OPTIONS.pchar
PKG_SUPPORTED_OPTIONS=	inet6

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Minet6)
CONFIGURE_ARGS+=	--with-ipv6
.endif

.if ${OPSYS} == "NetBSD"
.  include "../../net/net-snmp/buildlink3.mk"
CONFIGURE_ARGS+=	--with-snmp=${BUILDLINK_PREFIX.net-snmp}
LIBS+=			-lsnmp -lcrypto -ldes
.endif

INSTALLATION_DIRS=	${PKGMANDIR}/man8 sbin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pchar ${DESTDIR}${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/pchar.8 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
