# $NetBSD: Makefile,v 1.13 2008/06/19 15:04:55 taca Exp $

DISTNAME=	htmlsplit102
PKGNAME=	${RUBY_PKGPREFIX}-htmlsplit-1.0.2
PKGREVISION=	3
CATEGORIES=	www ruby
MASTER_SITES=	http://www.moonwolf.com/ruby/archive/
EXTRACT_SUFX=	.zip

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	http://www.moonwolf.com/ruby/htmlsplit.html
COMMENT=	Ruby HTML split/join library

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}
NO_CONFIGURE=	yes
NO_BUILD=	yes

INSTALLATION_DIRS=	${RUBY_VENDORLIB} ${RUBY_EG}/htmlsplit

do-install:
	${INSTALL_DATA} ${WRKSRC}/htmlsplit.rb ${DESTDIR}${PREFIX}/${RUBY_VENDORLIB}
	${INSTALL_DATA} ${WRKSRC}/splittest.rb ${DESTDIR}${PREFIX}/${RUBY_EG}/htmlsplit

.include "../../lang/ruby/modules.mk"
.include "../../mk/bsd.pkg.mk"
