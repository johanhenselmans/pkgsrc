# $NetBSD: buildlink3.mk,v 1.7 2006/07/08 23:11:01 jlam Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
LIBDVBPSI_BUILDLINK3_MK:=	${LIBDVBPSI_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libdvbpsi
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibdvbpsi}
BUILDLINK_PACKAGES+=	libdvbpsi
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}libdvbpsi

.if !empty(LIBDVBPSI_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.libdvbpsi+=	libdvbpsi>=0.1.3
BUILDLINK_ABI_DEPENDS.libdvbpsi+=	libdvbpsi>=0.1.6
BUILDLINK_PKGSRCDIR.libdvbpsi?=	../../multimedia/libdvbpsi
.endif	# LIBDVBPSI_BUILDLINK3_MK

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
