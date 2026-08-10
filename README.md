# Juul-OS
Start of my very own operating system. This project is designed to learn OS concepts practically, it is not designed to be the new Linux or anything just simple concepts working together in practice.

## Running this using qemu (MACOS my own system so don't shoot me if it isn't working for you)
!! cross compiler should be set up and available on your system !!

run following command to run the terminal (without tests):

`./run.sh`

qemu should start and show what is defined in the kernel

run follwoing command to run the test environment:

`./run-tests.sh`

The terminal screen should show you how many tests passed and how many failed.

Tests are mainly written for now to test the libc library and are certainly not complete but I guess it's good practice to have such an environment set up early.
