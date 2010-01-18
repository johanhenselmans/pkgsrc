# $NetBSD: buildlink3.mk,v 1.17 2009/08/26 19:56:40 sno Exp $

BUILDLINK_TREE+=	windowmaker

.if !defined(WINDOWMAKER_BUILDLINK3_MK)
WINDOWMAKER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.windowmaker+=		windowmaker>=0.80.2nb3
BUILDLINK_ABI_DEPENDS.windowmaker+=	windowmaker>=0.92.0nb10
BUILDLINK_PKGSRCDIR.windowmaker?=	../../wm/windowmaker

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/libungif/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../x11/libXft/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.endif # WINDOWMAKER_BUILDLINK3_MK

BUILDLINK_TREE+=	-windowmaker
