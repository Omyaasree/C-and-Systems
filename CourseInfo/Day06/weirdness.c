/* weirdness.c
 *
 *  Created on: Jul 31, 2024
 *      Author: phaskell
 */

#include <stdio.h>



int main(int argc, char** argv) {
	short tt = 258;
	short* tPtr = &tt;
	char* cPtr = (char*) tPtr; // ???
	printf("%hd\n", *cPtr);


	/**
	short ss = 32;
	short* sPtr = &ss;
	int* iPtr = (int*) sPtr; // ???
	printf("%d\n", *iPtr);
	**/

	return 0;
}
