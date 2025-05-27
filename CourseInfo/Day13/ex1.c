// filename: ex1.c
//
// Show how we can access the same memory from malloc()
// either as an array of chars or as an array of ints.
// The values in memory are INTERPRETED as being chars
// or ints, depending on which pointer variable we use.
//
// @author: phaskell


#include <stdio.h>
#include <stdlib.h>

int main() {
	char* cp = (char*) malloc(100);
	cp[0] = 'a';
	cp[1] = 'b';
	cp[2] = 'Z';
	cp[3] = '$';

	int* ip = (int*) cp;
	printf("%d\n", ip[0]);

	ip[0] = 609903200;
	printf("%c\n", cp[0]);
	printf("%c\n", cp[1]);
	printf("%c\n", cp[2]);
	printf("%c\n", cp[3]);

	return 0;
}

