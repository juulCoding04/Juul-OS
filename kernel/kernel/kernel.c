#include <stdio.h>
#include <string.h>

#include <kernel/tty.h>

void kernel_main(void) {
	terminal_init();
    terminal_writestring("Hello from terminal!\n");
    
    printf("\n---test printf char---\n");
    printf("hello %c\n", 'J');

    printf("\n---test printf string---\n");
    printf("hello %s\n", "there");

    printf("\n---test printf integer---\n");
    printf("digit: %d\n", 987654321);

    printf("\n---test printf neg int---\n");
    printf("neg: %d\n", -54321);

    printf("\n---test printf x---\n");
    printf("dig: %d = hex: %x", 10, 10);

    printf("\n--test printf percent and default---\n");
    printf("100%%; %h");
}
