#include <stdio.h>
#include <string.h>

#include <kernel/tty.h>

void kernel_main(void) {
	terminal_init();
    terminal_writestring("Hello from terminal!\n");

    printf("hello %c\n", 'J');

    // Testing memcpy
    char src[] = "test";
    char dest[10];
    memcpy(dest, src, 5);

    terminal_writestring("Source: ");
    terminal_writestring(src);
    terminal_writestring("\n");

    terminal_writestring("Destination: ");
    terminal_writestring(dest);
    terminal_writestring("\n");
}
