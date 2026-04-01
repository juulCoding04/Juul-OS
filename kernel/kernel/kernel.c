#include <stdio.h>

#include <kernel/tty.h>

void kernel_main(void) {
	terminal_init();
    terminal_writestring("Hello from terminal!");
}
