// filename: logic.c


#include <stdio.h>

int main() {
	// Logical "boolean" operation.
	int a = 77;
	int b = 13;
	printf("%d\n", (a && b) );

	// Bit-level operation.
	// What happens when we keep right-shifting a negative number?
	char w = -128;
	for (int count = 0; count < 10; count++) {
		printf("%d\n", w);
		w >>= 1;
	}

	return 0;
}
