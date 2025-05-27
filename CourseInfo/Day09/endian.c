#include <stdio.h>
#include <stdlib.h>

int main() {
	int value = 0x0a0b0c0d;
	char* cPtr = (char*) &value;
	
	for (int n = 0; n < 4; n++) {
		printf("%x %x\n", *(cPtr+n), cPtr[n]);
	}

	return 0;
}
