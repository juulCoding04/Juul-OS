#include <stddef.h>
#include <string.h>

void* memset(void* ptr, int value, size_t n) {
    unsigned char* buf = (unsigned char*) ptr;

    for (size_t i = 0; i < n; i++) {
        buf[i] = (unsigned char) value;
    }

    return ptr;
}
