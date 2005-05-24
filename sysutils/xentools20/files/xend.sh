#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: xend.sh,v 1.2 2005/04/01 19:06:12 bouyer Exp $
#
# PROVIDE: xend
# REQUIRE: disks network

if [ -f /etc/rc.subr ]; then
	. /etc/rc.subr
fi

name="xend"
rcvar=$name
command="@PREFIX@/sbin/xend"
command_interpreter="@RCD_INTERPRETER@"
start_cmd="@ECHO@ Starting ${name}. && ${command} start"
start_precmd="test_kern_privcmd"

test_kern_privcmd()
{
	if [ ! -f /kern/xen/privcmd ]; then
		@ECHO@ "${name}: Cannot find /kern/xen/privcmd!"
		exit 1
	fi
}

load_rc_config $name
run_rc_command "$1"
