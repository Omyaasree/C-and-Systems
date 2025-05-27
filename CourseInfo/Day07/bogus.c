/* bogus.c
 *
 * Run this in Windows BASH!
 */

#include <stdio.h>
#include <stdlib.h>




int main(int argc, char** argv) {

	int* iPtr = malloc(100 * sizeof(int));
	free(iPtr);
	int* jPtr = malloc(200 * sizeof(int));
	jPtr[0] = 5;
	iPtr[0] = 11;
	printf("done: %d\n", jPtr[0]);
	return 0;
}
