// filename:  memspeedhelper.c
//
// A method to make big random numbers.
//
// @author: phaskell


#include <stdio.h>
#include <stdlib.h>


// rand() only has 15 random bits.
// This method has multiple calls to rand() to make
// a number with 60 random bits.
long long myRand() {
	long long retval = 0;
	retval |= rand();
	retval <<= 15;
	retval |= rand();
	retval <<= 15;
	retval |= rand();
	retval <<= 15;
	retval |= rand();
	return retval;
}


int main() {
	// Show how a pointer-to-function can be printed.
	printf("Address of main is %p\n", main);

	// Find "biggest" random number from myRand().
	long long biggest = 0LL;
	srand(55);

	for (int i = 0; i < 100000000; i++) {
		long long tmp = myRand();
		if (tmp > biggest) { biggest = tmp; }
	}
	printf("%lld\n", biggest);
	return 0;
}
