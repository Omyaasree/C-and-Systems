#include <stdio.h>
#include <stdlib.h>

int main() {
	int* iPtr = malloc(100 * sizeof(int));
	int* iPtr2 = iPtr + 1;

	printf("%ld\n", (iPtr2 - iPtr) );
	printf("%p %p\n", iPtr2, iPtr);

	char* cPtr = (char*) iPtr;
	char* cPtr2 = (char*) iPtr2;
	printf("%ld\n", (cPtr2 - cPtr) );
	printf("%p %p\n", cPtr2, cPtr);

	double* dPtr = (double*) iPtr;
	double* dPtr2 = (double*) iPtr2;
	printf("%ld\n", (dPtr2 - dPtr) );
	printf("%p %p\n", dPtr2, dPtr);

	return 0;
}
