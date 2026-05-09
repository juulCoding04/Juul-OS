#!/bin/sh
set -e
./clean.sh
./headers.sh
./test.sh
./qemu-test.sh
