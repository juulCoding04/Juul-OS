#include "test_runner.h"

void test_mem(void);

int tests_passed = 0;
int tests_failed = 0;

void run_all_tests(void) {
    printf("=== Running tests ===\n");

    test_mem();

    printf("====================\n");
    printf("PASSED: %d\n", tests_passed);
    printf("FAILED: %d\n", tests_failed);
    printf("====================\n");
}
