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

    // Debug print showing serial driver correctly initialized
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

    // Cast the address of the multiboot info to a pointer of a custom struct for multiboot info
    // This allows us to get information out as defined in the specs for multiboot
    multiboot_info_t* mbi = (multiboot_info_t*)mbi_addr;

    multiboot_print_mmap(mbi);

    #ifdef RUN_TESTS
        run_all_tests();
        for(;;);
    #endif
}
