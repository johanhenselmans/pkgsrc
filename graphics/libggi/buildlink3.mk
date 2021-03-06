# $NetBSD: buildlink3.mk,v 1.13 2010/01/30 15:22:13 tnn Exp $

BUILDLINK_TREE+=	libggi

.if !defined(LIBGGI_BUILDLINK3_MK)
LIBGGI_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libggi+=	libggi>=2.2.2
BUILDLINK_PKGSRCDIR.libggi?=	../../graphics/libggi

.include "../../mk/bsd.fast.prefs.mk"

.if ${X11_TYPE} == "modular"
.include "../../x11/libXxf86dga/buildlink3.mk"
.include "../../x11/libXxf86vm/buildlink3.mk"
.endif

.include "../../devel/ncurses/buildlink3.mk"
.include "../../graphics/libgii/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/xextproto/buildlink3.mk"
.endif # LIBGGI_BUILDLINK3_MK

BUILDLINK_TREE+=	-libggi
