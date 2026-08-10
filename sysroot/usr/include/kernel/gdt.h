#include <stdint.h>

typedef struct {
    uint8_t accessed        : 1;
    uint8_t read_write      : 1;
    uint8_t direction       : 1;
    uint8_t executable      : 1;
    uint8_t descriptor_t    : 1;
    uint8_t privilege       : 2;
    uint8_t present         : 1;
} __attribute__((packed)) gdt_access_byte;

typedef struct {
    uint8_t limit_high      : 4;
    uint8_t reserved       : 1;
    uint8_t long_mode       : 1;
    uint8_t size            : 1;
    uint8_t granularity     : 1;
} __attribute__((packed)) gdt_flags_and_limit;

typedef struct {
    uint16_t limit_low;
    uint16_t base_low;
    uint8_t base_mid;
    gdt_access_byte access;
    gdt_flags_and_limit flags;
    uint8_t base_high;
} __attribute__((packed)) gdt_segment_descriptor;
