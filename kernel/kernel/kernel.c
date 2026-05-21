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

    if (mbi->flags & FLAG_MMAP) {
        printf("\nMMAP flag set!\n");
        multiboot_mmap_entry_t* mmap_start = (multiboot_mmap_entry_t*) mbi->mmap_addr;
        multiboot_mmap_entry_t* mmap_end = (multiboot_mmap_entry_t*) (mbi->mmap_addr + mbi->mmap_length);

        while (mmap_start < mmap_end) {
            const char* type_str;
            if (mmap_start->type == 1) {
                type_str = "usable";
            } else {
                type_str = "reserved";
            }

            uint32_t start = (uint32_t)mmap_start->base_addr;
            uint32_t end = (uint32_t)(mmap_start->base_addr + mmap_start->length);

            printf("0x%x - 0x%x  %s\n", start, end, type_str);
            mmap_start = (multiboot_mmap_entry_t*)((uint32_t)mmap_start + mmap_start->size + sizeof(uint32_t));
        }
    } else {
        printf("No memory map available!\n");
    }

    #ifdef RUN_TESTS
        run_all_tests();
        for(;;);
    #endif
}
