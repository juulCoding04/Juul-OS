#pragma once

#include <stdint.h>

extern uintptr_t __stack_chk_guard;
void __stack_chk_fail(void);
