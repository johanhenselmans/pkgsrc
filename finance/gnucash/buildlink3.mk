# $NetBSD: buildlink3.mk,v 1.15 2012/02/06 12:40:09 wiz Exp $

BUILDLINK_TREE+=	gnucash

.if !defined(GNUCASH_BUILDLINK3_MK)
GNUCASH_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gnucash+=	gnucash>=2.1.0
BUILDLINK_ABI_DEPENDS.gnucash+=	gnucash>=2.4.10nb1
BUILDLINK_PKGSRCDIR.gnucash?=	../../finance/gnucash

.include "../../devel/glib2/buildlink3.mk"
.endif # GNUCASH_BUILDLINK3_MK

BUILDLINK_TREE+=	-gnucash
