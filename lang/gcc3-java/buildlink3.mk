# $NetBSD$

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
GCC3JAVA_BUILDLINK3_MK:=	${GCC3JAVA_BUILDLINK3_MK}+

.include "../../mk/bsd.prefs.mk"

.if !empty(GCC3JAVA_BUILDLINK3_MK:M+)
.  if defined(GCC3_INSTALLTO_SUBPREFIX)
GCC3_PKGMODIF=			_${GCC3_INSTALLTO_SUBPREFIX}
.  endif
BUILDLINK_PACKAGES+=		gcc3java
BUILDLINK_DEPENDS+=		gcc3java
BUILDLINK_DEPENDS.gcc3java+=	gcc3${GCC3_PKGMODIF}-java>=${_GCC_REQD}
BUILDLINK_PKGSRCDIR.gcc3java?=	../../lang/gcc3-java

# Packages that link against shared libraries need a full dependency.
.  if defined(USE_GCC_SHLIB)
BUILDLINK_DEPMETHOD.gcc3java+=	full
.  else
BUILDLINK_DEPMETHOD.gcc3java?=	build
.  endif
.endif	# GCC3JAVA_BUILDLINK3_MK

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
