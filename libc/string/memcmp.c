#include <string.h>

int memcmp(const void* p1, const void* p2, size_t size) {
	const unsigned char* a = (const unsigned char*) p1;
	const unsigned char* b = (const unsigned char*) p2;

	// loop over given size
	for (size_t i = 0; i < size; i++) {
		if (a[i] < b[i]) return -1; // mem block a is smaller than mem block b
		if (a[i] > b[i]) return 1;  // mem block a is greater than mem block b
	}
	return 0; // if loop ends without entering any of the if's the mem blocks are equal
}
