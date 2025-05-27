// interpret.c
// Values in memory can be interpreted as different data types.


#include <stdio.h>
#include <stdlib.h>


// "byte" becomes an "alias" for "unsigned char".
typedef unsigned char byte;


int main() {
	printf("Sizes of int, long, long long: ");
	printf("%d %d %d\n\n", sizeof(int), sizeof(long), sizeof(long long));

	printf("Same data interpreted as different data TYPES:\n");
	byte* bPtr = malloc(4);
	bPtr[0] = 85; // 'U'
	bPtr[1] = 83; // 'S'
	bPtr[2] = 70; // 'F'
	bPtr[3] = 68; // 'D'
	bPtr[4] = 79; // 'O'
	bPtr[5] = 78; // 'N'
	bPtr[6] = 83; // 'S'
	bPtr[7] = 0; // end-of-string
	printf("%s\n", bPtr);

	float* fVal = (float*) bPtr;
	printf("%f\n", *fVal);

	double* dVal = (double*) bPtr;
	printf("%lf\n", *dVal);

	int* iVal = (int*) bPtr;
	printf("%d\n", *iVal);

	long long* lVal = (long long*) bPtr;
	printf("%lld\n\n\n", *lVal);

	printf("Sizes of different pointer types:\n");
	printf("sizeof ptr is %d\n", sizeof(bPtr));
	printf("sizeof ptr is %d\n", sizeof(fVal));
	printf("sizeof ptr is %d\n", sizeof(dVal));
	printf("sizeof ptr is %d\n", sizeof(iVal));
	printf("sizeof ptr is %d\n", sizeof(lVal));

	return 0;
}
