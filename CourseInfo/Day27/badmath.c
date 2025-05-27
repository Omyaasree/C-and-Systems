// badmath.c
//

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>


int a = 15;
int b = 0;
int c = 30;


void fpeHandler(int) {
	printf("Floating Point Error: %d %d %d\n", a, b, c);
	exit(1);
}


int main() {
	signal(SIGFPE, fpeHandler);

	printf("SIGFPE is %d\n", SIGFPE);

	c = a / b;
	printf("c is %d\n", c);
}
