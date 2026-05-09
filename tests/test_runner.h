#pragma once
#include <stddef.h>
#include <stdio.h>

extern int tests_passed;
extern int tests_failed;

#define ASSERT(cond, msg) \
    do { \
        if (cond) { tests_passed++; } \
        else { tests_failed++; printf("[FAIL] %s:%d - %s\n", __FILE__, __LINE__, msg); } \
    } while(0)

void run_all_tests(void);
