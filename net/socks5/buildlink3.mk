# $NetBSD: buildlink3.mk,v 1.8 2006/07/08 23:11:04 jlam Exp $

BUILDLINK_TREE+=	socks5

.if !defined(SOCKS5_BUILDLINK3_MK)
SOCKS5_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.socks5+=	socks5>=1.0.2
BUILDLINK_PKGSRCDIR.socks5?=	../../net/socks5
.endif # SOCKS5_BUILDLINK3_MK

BUILDLINK_TREE+=	-socks5
