#include <stdio.h>
#include <string.h>

#include <kernel/tty.h>

void kernel_main(void) {
	terminal_init();
    terminal_writestring("Hello from terminal!\n");

    int arr1[] = {1, 2, 3};
    int arr2[] = {1, 2, 3};
    int arr3[] = {1, 3, 3};

    int result_1_2 = memcmp(arr1, arr2, sizeof(arr1));

    if (result_1_2 == 0) {
        printf("arrays 1 and 2 are equal\n");
    } else {
        printf("arrays 1 and 2 are not equal");
    }

    int result_1_3 = memcmp(arr1, arr3, sizeof(arr1));
    if (result_1_3 == 0) {
        printf("arrays 1 and 3 are equal\n");
    } else {
        printf("arrays 1 and 3 are not equal");
    }
}
