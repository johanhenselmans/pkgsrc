# $NetBSD: options.mk,v 1.1 2005/06/08 13:20:04 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.wwwoffle
PKG_SUPPORTED_OPTIONS=	inet6

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Minet6)
CONFIGURE_ARGS+= --with-ipv6
.endif
