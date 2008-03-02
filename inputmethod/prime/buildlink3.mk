# $NetBSD$

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
PRIME_BUILDLINK3_MK:=	${PRIME_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	prime
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nprime}
BUILDLINK_PACKAGES+=	prime
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}prime

.if ${PRIME_BUILDLINK3_MK} == "+"
.include "../../lang/ruby/rubyversion.mk"
BUILDLINK_API_DEPENDS.prime+=	${RUBY_PKGPREFIX}-prime>=1.0.0.1
BUILDLINK_PKGSRCDIR.prime?=	../../inputmethod/prime
.endif	# PRIME_BUILDLINK3_MK

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
