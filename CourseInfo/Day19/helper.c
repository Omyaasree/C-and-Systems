/*************************************************
 * helper.c contains methods to help with sorting.
 *
 * @author Paul Haskell
 ************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "helper.h"



/** Assign random integer values to all elements in
 * the provided int array.
 * @param values the array to be filled in
 * @param L number of ints in the array ("length")
 */
void setValues(int* values, const int L) {
#ifdef linux
	srand48(time(0));
#else
	srand(time(0));
#endif
	const int MaxVal = 2*L;
	for(int i = L-1; i >= 0; i--) {
#ifdef linux
		values[i] = (int) (MaxVal * drand48());
#else
		values[i] = (int) (rand() % MaxVal);
#endif
	}
}


/** Validate that the array values are sorted in increasing order.
 * @param values the int array to validate
 * @param L number of ints in the array ("length")
 */
void validate(int* values, const int L)
{
	for(int i = L - 1; i > 0; i--) {
		if (values[i-1] > values[i]) {
			fprintf(stderr, "Sort failed\n");
			return;
		}
	}
	printf("Sort passed\n");
} // end validate()
