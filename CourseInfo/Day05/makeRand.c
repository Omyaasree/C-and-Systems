/* makeRand.c
 *
 *  Created on: Jul 31, 2024
 *      Author: phaskell
 */

#include <stdio.h>

unsigned int getRand() {
	static unsigned int state = 0xffffffff;
	unsigned char bit = state >> 31;
	state = (state << 27) ^ (state << 13) ^ (state << 6) ^ (state << 2);
	state |= bit;
	return state;
}

int main(int argc, char** argv) {
	for (int count = 0; count < 20; count++ ) {
		printf("%f ", ((double) getRand())/0xffffffff);
	}
	return 0;
}
