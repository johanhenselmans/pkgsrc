# $NetBSD: Makefile,v 1.48 2012/01/17 15:53:13 adam Exp $

DISTNAME=	sqlite-autoconf-3071100
PKGNAME=	sqlite3-3.7.11
CATEGORIES=	databases
MASTER_SITES=	http://www.hwaci.com/sw/sqlite/ \
		http://www.sqlite.org/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.sqlite.org/
COMMENT=	SQL Database Engine in a C Library
LICENSE=	public-domain

PKG_DESTDIR_SUPPORT=	user-destdir

.include "options.mk"

USE_LIBTOOL=		yes
USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes

PKGCONFIG_OVERRIDE+=	sqlite3.pc.in

INSTALLATION_DIRS+=	${PKGMANDIR}/man1

.include "../../mk/bsd.prefs.mk"

# In the past, Linux had database corruption issues with pread, so
# only enable it on safe platforms.
CFLAGS.NetBSD+=		-DUSE_PREAD

# Darwin < 9 (Mac OS X < 10.5 "Leopard") doesn't have gethostuuid(2)
.if !empty(MACHINE_PLATFORM:MDarwin-[0-8].*-*)
CFLAGS+=		-DSQLITE_ENABLE_LOCKING_STYLE=0
.endif

.if ${OPSYS} == "Minix"
CPPFLAGS+=	-DSQLITE_OMIT_LOAD_EXTENSION -DSQLITE_MUTEX_NOOP -DSQLITE_OMIT_WAL
CONFIGURE_ARGS+=	--enable-readline=no
.endif

# This define includes the sqlite3_unlock_notify() API in the build.
# It is required by Firefox 4.x.
CFLAGS+=		-DSQLITE_ENABLE_UNLOCK_NOTIFY=1

# Uses dlopen and friends but doesn't use -ldl on Linux.
# See http://www.sqlite.org/cvstrac/tktview?tn=3555
LIBS+=			${BUILDLINK_LDADD.dl}

.include "../../devel/readline/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
