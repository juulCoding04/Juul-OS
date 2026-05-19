#include <stdio.h>
#include <string.h>

#include <kernel/tty.h>
#include <kernel/serial.h>

#ifdef RUN_TESTS
#include "tests/test_runner.h"
#endif

void kernel_main(void) {
	terminal_init();
    puts("Hello from terminal!\n");

    if (serial_init() != 0) {
        printf("Something wrong with serial init\n");
    } else {
        printf("Serial initialized\n");
    }

    printf("Hello from kernel again!");


    #ifdef RUN_TESTS
        run_all_tests();
        for(;;);
    #endif
}
