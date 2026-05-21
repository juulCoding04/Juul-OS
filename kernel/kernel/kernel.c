#include <stdint.h>
#include <stdio.h>
#include <string.h>

#include <kernel/tty.h>
#include <kernel/serial.h>
#include <kernel/multiboot.h>

#ifdef RUN_TESTS
#include "tests/test_runner.h"
#endif

void kernel_main(uint32_t magic, uint32_t mbi_addr) {
	terminal_init();

    if (serial_init() != 0) {
        printf("Failed to initialize serial");
    } else {
        printf("Serial initialized\n");
    }

    if (magic != MULTIBOOT_MAGIC) {
        printf("Not booted by Multiboot!\n");
        printf("magic: 0x%x\n", magic);
        for(;;);
    }

    printf("Booted correctly, magic: 0x%x\n", magic);
    printf("Multiboot info at: 0x%x\n", mbi_addr);

    multiboot_info_t* mbi = (multiboot_info_t*)mbi_addr;

    printf("Lower memory: %d KB\n", mbi->mem_lower);
    printf("Upper memory: %d KB\n", mbi->mem_upper);

    #ifdef RUN_TESTS
        run_all_tests();
        for(;;);
    #endif
}
