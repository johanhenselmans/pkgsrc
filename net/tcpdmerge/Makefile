# $NetBSD: Makefile,v 1.9 2006/11/09 09:36:41 rillig Exp $

DISTNAME=	tcpdmerge-1.0
CATEGORIES=	net
MASTER_SITES=	http://phantom.nemoto.ecei.tohoku.ac.jp/~akiraka/tcpdmerge/
DISTFILES=	tcpdmerge.c 00README.TXT

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://phantom.nemoto.ecei.tohoku.ac.jp/~akiraka/tcpdmerge/
COMMENT=	Merge two tcpdump output files

PKG_DESTDIR_SUPPORT=	user-destdir

USE_BSD_MAKEFILE=	yes

WRKSRC=		${WRKDIR}

INSTALLATION_DIRS+=	bin

post-extract:
	cp ${FILESDIR}/Makefile ${WRKSRC}

.include "../../net/libpcap/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
