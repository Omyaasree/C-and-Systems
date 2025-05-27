// filename: demo2.c
// @author: phaskell
//
// Show how 'static' works, for global variables AND method variables.


#include <stdio.h>

static int value = 22;

static int getValue() { return 44; }

int counter = 0;


int getCount() {
	/* static */ int n = 100;
	n++;
	return n;
}

int main() {
	for (int i = 0; i < 10; i++) {
		printf("count is %d\n", getCount());
	}
}
