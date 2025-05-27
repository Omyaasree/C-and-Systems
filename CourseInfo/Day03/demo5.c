// filename: demo5.c
//
#include <stdio.h>

extern int globalVar;
extern void counter();

int main() {
	printf("%d\n", globalVar);
	for (int i = 0; i < 10; i++) {
		counter();
	}
}
