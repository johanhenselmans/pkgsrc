# $NetBSD: Makefile,v 1.4 2010/08/21 16:34:35 seb Exp $
#

DISTNAME=		Test-MinimumVersion-0.101080
PKGNAME=		p5-${DISTNAME:S/101080/101.080/}
PKGREVISION=		2
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Test-MinimumVersion/
COMMENT=		Test to prove a module requires newer perl than expected
LICENSE=		${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=		p5-File-Find-Rule-[0-9]*:../../devel/p5-File-Find-Rule
DEPENDS+=		p5-File-Find-Rule-Perl-[0-9]*:../../devel/p5-File-Find-Rule-Perl
DEPENDS+=		p5-Perl-MinimumVersion>=1.20:../../devel/p5-Perl-MinimumVersion
DEPENDS+=		p5-YAML-Tiny>=1.40:../../textproc/p5-YAML-Tiny
DEPENDS+=		{perl>=5.10.0,p5-version>=0.7000}:../../devel/p5-version

BUILD_DEPENDS+=		p5-Test-Tester-[0-9]*:../../devel/p5-Test-Tester

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Test/MinimumVersion/.packlist
PERL5_MODULE_TYPE=	Module::Install::Bundled

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
