#include "../test_runner.h"
#include <string.h>

void test_mem(void) {
    // memcmp
    ASSERT(memcmp("abc", "abc", 3) == 0, "memcmp equal strings");
    ASSERT(memcmp("abc", "abd", 3) < 0, "memcmp less than");
    ASSERT(memcmp("abd", "abc", 3) > 0, "memcmp greater than");
    ASSERT(memcmp("abc", "abc", 0) == 0, "memcmp zero length");
}
