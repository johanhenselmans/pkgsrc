# $NetBSD: buildlink3.mk,v 1.19 2012/02/06 12:41:21 wiz Exp $

BUILDLINK_TREE+=	libgnomecups

.if !defined(LIBGNOMECUPS_BUILDLINK3_MK)
LIBGNOMECUPS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libgnomecups+=	libgnomecups>=0.2.0
BUILDLINK_ABI_DEPENDS.libgnomecups?=	libgnomecups>=0.2.3nb8
BUILDLINK_PKGSRCDIR.libgnomecups?=	../../print/libgnomecups

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../print/cups/buildlink3.mk"
.endif # LIBGNOMECUPS_BUILDLINK3_MK

BUILDLINK_TREE+=	-libgnomecups
