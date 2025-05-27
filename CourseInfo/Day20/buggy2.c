// filename: buggy2.c
//
// Debug this with valgrind or use the corefile.


#include <stdio.h>


int main() {
	char* buf = (char*) malloc(1024);

	// Put letters and numbers into memory.
	int index = 1024;
	while (index >= 0) {
		buf[--index] = 'A' + (index % 26);
		buf[--index] = 'a' + (index % 26);
		buf[--index] = '0' + (index % 10);
	}
	buf[1023] = 0; // end of string

	// Print values.
	printf("%s\n", (const char*) buf);

	free(buf);
	return 0;
}

