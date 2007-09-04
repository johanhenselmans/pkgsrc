# $NetBSD$

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
LIBPAPER_BUILDLINK3_MK:=	${LIBPAPER_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	libpaper
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibpaper}
BUILDLINK_PACKAGES+=	libpaper
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}libpaper

.if ${LIBPAPER_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.libpaper+=	libpaper>=1.1.22
BUILDLINK_PKGSRCDIR.libpaper?=	../../print/libpaper
.endif	# LIBPAPER_BUILDLINK3_MK

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
