/* crash3.c
 *
 * @author: phaskell
 */



#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
	int* iPtr = (int*) malloc(4*100);
	iPtr -= 4000;
	iPtr[0] = 321;

	fprintf(stderr, "done\n"); fflush(stderr);
	return 0;
}
