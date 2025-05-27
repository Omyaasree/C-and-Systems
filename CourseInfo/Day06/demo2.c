// filename: demo2.c
// Use pointers to change value of variable in the calling function
// (not the called function).


#include <stdio.h>


void doubler(int* inp) {
	// inp = 0x10000;  change the pointed-to ADDRESS.
	*inp *= 2;  // Change the VALUE OF the POINTED-TO thing.
}



int main() {
	int var = 22;
	doubler(&var);
	printf("Value of pointer is %p\n", &var);

	printf("%d\n", var);
	printf("%d\n", *(&var - 400) ); // contents of some other memory address

	return 0;
}
