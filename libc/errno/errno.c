#include <errno.h>

static int _errno_value = 0;

int *_errno_location(void) {
    return &_errno_value;
}
