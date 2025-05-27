/* filename: fastalloc.c
 *
 * Do memory allocation locally, for really fast speed?!?
 */


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>


// Our local memory cache. Quickly allocate memory from here.
// World's laziest memory allocator...
char bigBuffer[65536];
static char* next = &(bigBuffer[0]);

char* allocator(int size) {
	char* retval = next;
	next += size;
	// Need some sort of overflow detection.
	return retval;
}


int main() {
	// Get memory from our local allocator.
	int* buf1 = (int*) allocator(10);
	int* buf2 = (int*) allocator(10);

	// Initialize buf1 and buf2 values.
	for (int n = 0; n < 10; n++) {
		buf1[n] = n;
	}
	for (int n = 0; n < 10; n++) {
		buf2[n] = n+256;
	}

	// Print buf1 values.
	for (int n = 0; n < 10; n++) {
		printf("%d ", buf1[n]);
	}
	printf("\n");

	return 0;
}
