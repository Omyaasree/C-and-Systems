#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


long long finalValue = -1;

void cleanup(void) {
	fprintf(stderr, "Final value is %Ld\n", finalValue);
}

int main() {
	atexit(cleanup);

	for (long long num = 0LL; num < 10000000000LL; num++) {
		double tmp = sqrt(num);
		finalValue = num;
	}
	return 0;
}
