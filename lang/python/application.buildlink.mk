# $NetBSD: application.buildlink.mk,v 1.1 2002/01/15 17:23:24 drochner Exp $

.include "../../lang/python/pyversion.mk"

# replace shell magic by python version specific path

_PYTHON_PATCH_SCRIPT_SED=	-e "1s;^\#!.*python;\#!${PYTHONBIN};"

.if defined(PYTHON_PATCH_SCRIPTS)
post-build:
.for s in ${PYTHON_PATCH_SCRIPTS}
	${SED} ${_PYTHON_PATCH_SCRIPT_SED} <${WRKSRC}/$s >${WRKSRC}/$s.patched
	${MV} ${WRKSRC}/$s.patched ${WRKSRC}/$s
.endfor
.endif
