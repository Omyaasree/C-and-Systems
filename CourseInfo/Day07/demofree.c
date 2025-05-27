// filename: demofree.c


#include <stdio.h>
#include <stdlib.h>

void initialize(int* data, int length) {
	for (int c = 0; c < length; c++) {
		data[c] = c * c - c;
	}
}

void print(int* data, int length) {
	for (int c = 0; c < length; c++) {
		printf("%d ", data[c]);
	}
	printf("\n");
}

int main() {
	int* myArray = (int*) malloc(40 * sizeof(int));
	initialize(myArray, 40);
	print(myArray, 40);
	free(myArray);
	print(myArray, 40); // will crash

	return 0;
}
