// filename: demomalloc.c


#include <stdio.h>
#include <stdlib.h>

int main() {
	double* bigArray = (double*) malloc(4000 * sizeof(double));
	bigArray[0] = 0;
	bigArray[3999] = 3999.999;

	// sizeof() is quirky with array arguments.
	// Better to use it just with data types as arguments.
	printf("%ld\n", sizeof(bigArray));
	double array2[4000];
	printf("%ld\n", sizeof(array2));

	return 0;
}


