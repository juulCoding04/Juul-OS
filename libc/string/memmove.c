#include <stddef.h>
#include <string.h>

void* memmove(void* destptr, const void* srcptr, size_t numBytes) {
	unsigned char* dest = (unsigned char*) destptr;
	const unsigned char* src = (const unsigned char*) srcptr;

	if (dest == src || numBytes == 0) return dest;

	if (dest < src || dest >= src + numBytes) {
		for (size_t i = 0; i < numBytes; i++) {
			dest[i] = src[i];
		}
	} else {
		for (size_t i = numBytes; i > 0; i--) {
			dest[i-1] = src[i-1];
		}
	}
	return dest;
}
