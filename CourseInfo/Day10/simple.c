// simple.c
//
// Interpret the same values in memory as if they were different
// data types.
//
// @author: phaskell


#include <stdio.h>
#include <stdlib.h>


/** Check this out!
 */
typedef unsigned char byte;


int main() {
	printf("Same data interpreted as different data TYPES:\n");
	byte* bPtr = malloc(8);
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

	void* vPtr = (void*) bPtr;

	printf("Sizes of different pointer types:\n");
	printf("sizeof byte ptr is %ld\n", sizeof(bPtr));
	printf("sizeof float ptr is %ld\n", sizeof(fVal));
	printf("sizeof double ptr is %ld\n", sizeof(dVal));
	printf("sizeof int ptr is %ld\n", sizeof(iVal));
	printf("sizeof long long ptr is %ld\n", sizeof(lVal));
	printf("sizeof void ptr is %ld\n", sizeof(vPtr));
	printf("sizeof void is %ld\n", sizeof(*vPtr));

	return 0;
}
