# $NetBSD: Makefile,v 1.12 2012/02/06 12:40:34 wiz Exp $
#

PKGNAME=		${RUBY_PKGPREFIX}-clutter-cairo-${VERSION}
COMMENT=		Ruby binding for Clutter Cairo library
PKGREVISION=		11
CATEGORIES=		graphics

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	${RUBY_PKGPREFIX}-clutter-core>=${VERSION}:../../graphics/ruby-clutter-core

RUBY_EXTCONF_SUBDIRS=	clutter-cairo
RUBY_VERSION_SUPPORTED= 18

USE_TOOLS+=	pkg-config

BUILDLINK_DEPMETHOD.ruby-gnome2-glib=	build
.include "../../devel/ruby-gnome2-glib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../graphics/clutter-cairo/buildlink3.mk"
.include "../../graphics/ruby-rcairo/buildlink3.mk"
.include "../../graphics/ruby-clutter/Makefile.common"
