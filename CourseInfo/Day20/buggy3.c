// filename: buggy3.c
//
// Debug with a debugger, gdb, or use the corefile.


#include <stdio.h>

int a(int);
int b(int);
int c(int);

int a(int input) {
	if (input < 10) { return 10; }
	return b(input + 1);
}

int b(int input) {
	if (input < 0) { return 0; }
	return c(input - 1);
}

int c(int input) {
	if (input < 11) { return 11; }
	return a(input + 1);
}


int main() {
	// Print result.
	printf("%d\n", a(100));

	return 0;
}

