# $NetBSD: Makefile,v 1.40 2010/02/19 19:23:50 joerg Exp $

PKGNAME=	${DISTNAME:S/sasl/saslauthd/}

CONFLICTS+=	cyrus-sasl<2.1.15nb2

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../security/cyrus-sasl/Makefile.common"

COMMENT=		Cyrus SASL plaintext authentication daemon

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}

BUILD_TARGET=		all saslcache

SASLSOCKETDIR?=		${VARBASE}/run/saslauthd
BUILD_DEFS+=		SASLSOCKETDIR
FILES_SUBST+=		SASLSOCKETDIR=${SASLSOCKETDIR:Q}
CONFIGURE_ARGS+=	--with-saslauthd=${SASLSOCKETDIR:Q}
CONFIGURE_ARGS+=	--with-openssl=${SSLBASE:Q}

BUILD_DIRS=		saslauthd

.include "options.mk"

RCD_SCRIPTS=		saslauthd
FILES_SUBST+=		ROOT_USER=${REAL_ROOT_USER:Q}

INSTALLATION_DIRS=	bin

.include "../../security/openssl/buildlink3.mk"

SUBST_CLASSES+=		sysconf
SUBST_MESSAGE.sysconf=	Fixing path to ${PKG_SYSCONFDIR}
SUBST_STAGE.sysconf=	post-build
SUBST_FILES.sysconf=	saslauthd/LDAP_SASLAUTHD saslauthd/saslauthd.mdoc
SUBST_SED.sysconf=	-e "s,/usr/local/etc/,${PKG_SYSCONFDIR}/,g"

post-install:
	for f in saslcache ; do				\
		${INSTALL_PROGRAM} ${WRKSRC}/saslauthd/$$f \
			${DESTDIR}${PREFIX}/bin/$$f;	\
	done
.if !empty(PKG_OPTIONS:Mldap)
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/cyrus-saslauthd
	${INSTALL_DATA} ${WRKSRC}/saslauthd/LDAP_SASLAUTHD		\
		${DESTDIR}${PREFIX}/share/doc/cyrus-saslauthd
.endif

.include "../../mk/bsd.pkg.mk"
