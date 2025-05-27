// filename: demo4.c
#include <stdio.h>

static int idValue;


static double getPi() { return 3.141; }

int globalVar = 44;

void counter() {
	static int cntr = 0;
	printf("counter is %d\n", cntr);
	cntr++;
}
