#! /bin/sh
# $NetBSD: awk-test.sh,v 1.5 2005/11/19 22:55:24 rillig Exp $
#

set -e

mydir=`dirname "$0"`
. "${mydir}/tests.subr"

#
# Assignment of variables from the command line. The Solaris
# /usr/bin/awk does not conform to the POSIX specification, but passes
# the right hand side of the assignment uninterpreted. It fails the
# cmd.3 test case. The "for" loop makes sure that awk can handle strings
# of 4096 bytes length.
#
test_assignment "cmd.1" \
	"foo" "foo"
test_assignment "cmd.2" \
	"foo bar baz" "foo bar baz"
test_assignment "cmd.3" \
	"CPPFLAGS=\\\"-Dfoo=bar\\\"" "CPPFLAGS=\"-Dfoo=bar\""
line="a"
for i in 0 1 2 3 4 5 6 7 8 9 10 11 12; do
	test_assignment "cmd.2^${i}" "${line}" "${line}"
done

#
# Passing strings from stdin to stdout. awk should be able to handle at
# least 2^12 characters per line.
#
# Solaris 9 /usr/bin/awk: 2559 bytes
# Solaris 9 /usr/bin/nawk: 6144 bytes
#
line="a"
for i in 0 1 2 3 4 5 6 7 8 9 10 11 12; do
	test_passline "line.2^${i}" "${line}"
	line="${line}${line}"
done
