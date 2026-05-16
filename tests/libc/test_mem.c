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

    // strlen
    ASSERT(strlen("hello") == 5, "strlen handles normal strings");
    ASSERT(strlen("") == 0, "strlen handles empty strings");

    // memset
    char str[5] = "hello";
    memset(str+1, '.', 3*sizeof(char));
    ASSERT(str[0] == 'h', "memset starts correctly");
    ASSERT(str[1] == '.', "memset fills correctly");
    ASSERT(str[4] == 'o', "memset ends correctly");
}
