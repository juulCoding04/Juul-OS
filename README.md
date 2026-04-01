# Juul-OS
Start of my very own operating system

## Running this using qemu (MACOS my own system so don't shoot me if it isn't working for you)
!! cross compiler should be set up and available on your system !!

run following commands:

`./clean.sh`

`./headers.sh`

`./build.sh`

`qemu-system-i386 -kernel sysroot/boot/myos.kernel`

qemu should start and show what is defined in the kernel
