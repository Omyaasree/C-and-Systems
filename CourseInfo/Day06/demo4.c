// filename: demo4.c


#include <stdio.h>
#include <stdlib.h>

int main() {
	int* p1 = malloc(1000);
	int p2[1000];

	// The sizeof() operator is confusing with arrays.
	// Better to use it just with data types as arguments.
	printf("size of p1 is %ld\n", sizeof(p1));
	printf("size of p2 is %ld\n", sizeof(p2));

	p2[255] = 255;
	p1[255] = 155; // this is an error! Only 250 ints in the 'p1' array.

	return 0;
}
