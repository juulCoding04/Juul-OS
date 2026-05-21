#include <stdio.h>
#include <string.h>

#include <kernel/tty.h>
#include <kernel/serial.h>

#ifdef RUN_TESTS
#include "tests/test_runner.h"
#endif

void kernel_main(void) {
	terminal_init();

    if (serial_init() != 0) {
        printf("Failed to initialize serial");
    } else {
        printf("Serial initialized\n");
    }

    #ifdef RUN_TESTS
        run_all_tests();
        for(;;);
    #endif
}
