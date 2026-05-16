#include <stdio.h>
#include <string.h>

#include <kernel/tty.h>

#ifdef RUN_TESTS
#include "tests/test_runner.h"
#endif

void kernel_main(void) {
	terminal_init();
    puts("Hello from terminal!\n");


    #ifdef RUN_TESTS
        run_all_tests();
        for(;;);
    #endif
}
