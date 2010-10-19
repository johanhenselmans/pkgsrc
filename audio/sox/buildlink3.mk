# $NetBSD: buildlink3.mk,v 1.9 2009/03/20 19:25:03 joerg Exp $

BUILDLINK_TREE+=	sox

.if !defined(SOX_BUILDLINK3_MK)
SOX_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.sox+=	sox>=14.3.1
BUILDLINK_ABI_DEPENDS.sox+=	sox>=14.3.1
BUILDLINK_PKGSRCDIR.sox?=	../../audio/sox
.endif # SOX_BUILDLINK3_MK

BUILDLINK_TREE+=	-sox
