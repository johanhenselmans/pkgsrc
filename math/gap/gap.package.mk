# $NetBSD$
#
# Set GAP_PKG_NAME in your Makefile. More may appear here later.

DEPENDS+=       	gap-4.3:../../math/gap
GAP_DIRECTORY=  	${LOCALBASE}/lib/gap4.3
GAP_PKG_DIRECTORY=	${GAP_DIRECTORY}/pkg/${GAP_PKG_NAME}
