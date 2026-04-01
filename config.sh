SYSTEM_HEADER_PROJECTS="libc kernel"
PROJECTS="libc kernel"

export PATH="/opt/cross/bin:$PATH"

export MAKE=${MAKE:-make}
export TARGET=$(./default-host.sh)

export AR=$TARGET-ar
export AS=$TARGET-as
export CC=$TARGET-gcc

export PREFIX=/usr
export EXEC_PREFIX=$PREFIX
export BOOTDIR=/boot
export LIBDIR=$EXEC_PREFIX/lib
export INCLUDEDIR=$PREFIX/include

export SYSROOT=$(pwd)/sysroot
export CC="$CC --sysroot=$SYSROOT"
