// filename: chars.c
//
// Show off atexit() method.
// Show off arrays and pointers working together.
//
// @author: phaskell


#include <stdio.h>
#include <stdlib.h>


void cleanup() {
	printf("...that's all, folks!\n");
}


int main() {
	// "Register" cleanup() to be called when the program exits.
	atexit(cleanup);

	// Print out all the ASCII chars.
	// Need to be clever with the for() loop, or it will loop forever.
	for (char c = -128; c < 127; c++) {
		printf("%d: %c\n", (int) c, c);
	}
	printf("%d: %c\n", 127, 127);

	// Arrays and pointers.
	int data1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int* data2 = (int*) data1;
	printf("sizeof(data1): %ld\n", sizeof(data1));
	printf("sizeof(data2): %ld\n", sizeof(data2));

	// data1++; // This is not allowed.
	data2++;
	printf("%d %ld\n", *data2, sizeof(data2));

	return 56; // Hey, nothing's stopping us.
}
