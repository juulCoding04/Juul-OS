#include <stdio.h>

#if defined(__is_libk)
#include <kernel/tty.h>
#include <kernel/serial.h>
#endif

int putchar(int ic) {
#if defined(__is_libk)
    char c = (char)(ic);
    terminal_write(&c, sizeof(c));
    serial_putchar(c); // Now this serial is standardly called in libc putchar but when no serial driver imported we don't want this so should move inside an ifdef block or something
#else
    #TODO: system call
#endif
    return ic;
}
