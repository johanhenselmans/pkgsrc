# $NetBSD: Makefile,v 1.5 2010/09/08 20:35:11 sno Exp $

DISTNAME=	Sub-Name-0.05
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Sub/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Sub-Name/
COMMENT=	Perl 5 module to (re)name a sub
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=	auto/Sub/Name/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
