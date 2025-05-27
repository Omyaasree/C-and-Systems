// example.c
//
// Show how free works with malloc()
//
// @author: phaskell


#include <stdio.h>
#include <stdlib.h>

int main() {
	unsigned char* data = (unsigned char*) malloc(1000000000LL);

	for (unsigned long long i = 0; i < 1000000000LL; i++) {
		data[i] = i & 255;
	}

	free(data);
	return 0;
}
