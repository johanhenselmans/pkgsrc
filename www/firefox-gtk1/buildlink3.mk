# $NetBSD: buildlink3.mk,v 1.4 2005/05/14 15:27:10 taya Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
FIREFOX_GTK2_BUILDLINK3_MK:=	${FIREFOX_GTK2_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	firefox-gtk1
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nfirefox-gtk1}
BUILDLINK_PACKAGES+=	firefox-gtk1

.if !empty(FIREFOX_GTK2_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.firefox-gtk1+=	firefox-gtk1>=1.0
BUILDLINK_RECOMMENDED.firefox-gtk1+=	firefox-gtk1>=1.0.6
BUILDLINK_PKGSRCDIR.firefox-gtk1?=	../../www/firefox-gtk1
.endif	# FIREFOX_GTK2_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
