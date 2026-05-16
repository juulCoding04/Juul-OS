#include "../test_runner.h"
#include <string.h>

void test_mem(void) {
    // memcmp
    ASSERT(memcmp("abc", "abc", 3) == 0, "memcmp equal strings");
    ASSERT(memcmp("abc", "abd", 3) < 0, "memcmp less than");
    ASSERT(memcmp("abd", "abc", 3) > 0, "memcmp greater than");
    ASSERT(memcmp("abc", "abc", 0) == 0, "memcmp zero length");

    // memcpy
    char dest[8] = {0};
    char canary = dest[5];
    memcpy(dest, "hello", 5);
    ASSERT(dest[4] == 'o', "memcpy copies correctly");
    ASSERT(dest[5] == canary, "memcpy doesn't overwrite past n");
}
