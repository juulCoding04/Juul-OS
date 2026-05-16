#!/bin/sh
set -e
. ./headers.sh

(cd libc && DESTDIR="$SYSROOT" $MAKE install)

(cd kernel && DESTDIR="$SYSROOT" $MAKE test)

