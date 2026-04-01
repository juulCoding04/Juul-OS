#include <string.h>

void* memcpy(void* restrict to, const void* restrict from, size_t size) {
	unsigned char* dst = (unsigned char*) to;
	const unsigned char* src = (const unsigned char*) from;

	// loop over the length given
	for(size_t i = 0; i < size; i++) {
		dst[i] = src[i]; // set each bit in the destination equal to coresponding bit in the source
	}
	return to;
}
