# $NetBSD$

BUILDLINK_DEPTH:=				${BUILDLINK_DEPTH}+
PYRLRENDERPM_BUILDLINK3_MK:=	${PYRLRENDERPM_BUILDLINK3_MK}+

.include "../../lang/python/pyversion.mk"

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	pyrlrenderpm
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Npyrlrenderpm}
BUILDLINK_PACKAGES+=	pyrlrenderpm

.if !empty(PYRLRENDERPM_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.pyrlrenderpm+=	${PYPKGPREFIX}-reportlab-renderPM-[0-9]*
BUILDLINK_PKGSRCDIR.pyrlrenderpm?=	../../print/py-reportlab-renderPM
.endif	# PYRLRENDERPM_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
