# $NetBSD: Makefile,v 1.17 2006/06/12 16:28:09 wiz Exp $
#

DISTNAME=	lgeneral-1.1.1
PKGREVISION=	10
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=lgeneral/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://lgames.sourceforge.net/index.php?project=LGeneral
COMMENT=	Panzer General play-a-like, uses Panzer General data files

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	YES

CONFIGURE_ARGS+=	--disable-dl

.include "../../devel/SDL/buildlink3.mk"
.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
