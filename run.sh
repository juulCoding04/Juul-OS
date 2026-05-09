#!/bin/sh
set -e
./clean.sh
./headers.sh
./build.sh
./qemu.sh
