#include <kernel/multiboot.h>
#include <stdio.h>

void multiboot_print_mmap(multiboot_info_t *mbi) {
    if (!(mbi->flags & FLAG_MMAP)) {
        printf("No memory map available\n");
        return;
    }

    printf("Memmory map:\n");
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
        uint32_t end = (uint32_t)(mmap_start->base_addr + mmap_start->length - 1);

        printf("0x%x - 0x%x  %s\n", start, end, type_str);
        mmap_start = (multiboot_mmap_entry_t*)((uint32_t)mmap_start + mmap_start->size + sizeof(uint32_t));
    }
}
