// asserts.c
//


#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


// Function to get a positive number from keyboard
// More work to do!
double getVal() {
	double retval;
	const int numRead = scanf("%lf", &retval);

	assert(numRead == 1);
	return retval;
}


// Main module
int main() {
	printf("Enter a number: "); fflush(stdout);
	double num = getVal();
	assert(num >= 0.0);

	printf("Square root of your number is %lf\n", sqrt(num));

	return 0;
}
