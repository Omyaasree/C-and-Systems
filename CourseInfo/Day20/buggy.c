// filename: buggy.c
//
// Debug this with an IDE and valgrind.


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int main() {
	double* nums = (double*) malloc(sizeof(double) * 400);

	for (int i = 0; i <= 400; i++) {
		nums[i] = i / 10.0;
	}

	return 0;
}
