# $NetBSD$

BUILDLINK_TREE+=	gssdp

.if !defined(GSSDP_BUILDLINK3_MK)
GSSDP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gssdp+=	gssdp>=0.6.4
BUILDLINK_PKGSRCDIR.gssdp?=	../../net/gssdp

.include "../../devel/glib2/buildlink3.mk"
.include "../../net/libsoup24/buildlink3.mk"
.endif	# GSSDP_BUILDLINK3_MK

BUILDLINK_TREE+=	-gssdp
