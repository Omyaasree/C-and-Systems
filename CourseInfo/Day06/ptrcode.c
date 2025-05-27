// filename: ptrcode.c

#include <stdio.h>

int main() {
	short s1 = 44;
	short* sptr = &s1;
	sptr = (short*) 77;
	printf("%p\n", sptr);
	printf("%hd\n", *sptr);
}
