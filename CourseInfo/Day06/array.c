#include <stdio.h>

int main() {
	long bigArray[2000];

	long* thePtr = bigArray;
	printf("First: 0x%p\n", thePtr);

	thePtr = &(bigArray[0]);
	printf("Second: 0x%p\n", thePtr);

	return 0;
}
