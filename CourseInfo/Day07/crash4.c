/* crash4.c
 *
 * @author: phaskell
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char** argv) {
	char* cPtr;
	strcpy(cPtr, "The quick brown fox jumps over the lazy dog");
	cPtr = malloc(20);
	free(cPtr);
	strcpy(cPtr, "The quick brown fox jumps over the lazy dog");

	printf("done\n"); fflush(stdout);
	return 0;
}
