#!/bin/sh
#
#	$NetBSD$
#
# PROVIDE: spamd

. /etc/rc.subr

name="spamd"                      
rcvar=$name         
command="/usr/pkg/bin/${name}"
command_args="-r /var/run/${name}.pid"
command_interpreter="@PREFIX@/bin/perl"
pidfile="/var/run/${name}.pid"
              
load_rc_config $name
run_rc_command "$1"
