// AddrDemo.c
//
// Show actual addresses of a program's memory regions.
//
// @author: phaskell


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


const char *const Name = "Your Name Here";


int main() {
	int* arr = (int*) malloc(sizeof(int) * 10); // on the heap
	int val; // on the stack

	printf("code:\t0x%p\n", main);

	printf("const:\t0x%p (+ %Ld)\n",
		Name, (long long) Name - (long long) main);

	printf("heap:\t0x%p (+ %Ld)\n",
		arr, (long long) arr - (long long) Name);

	printf("stack:\t0x%p (+ %Ld)\n",
		&val, (long long) &val - (long long) arr);

	// Clean up.
	free(arr);
	return 0;
}
