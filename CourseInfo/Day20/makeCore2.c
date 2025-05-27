/* filename: makeCore2.c
 *
 * OCCASIONALLY makes corefiles.
 * Debug a corefile to see why.
 */


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>


static int initialized = 0;


int getRand() {
	if (!initialized) {
		srand(time(0));
		initialized = 1;
	}
	return rand() % 100;
}


int handleInt(int x) {
	int randVal = getRand();
	printf("\t%d %d\n", x, randVal);
	if (randVal < 5) {
		return x / randVal;
	}
	return handleInt(randVal);
}


int main() {
	printf("Value is %d\n", handleInt(50));
	return 0;
}
