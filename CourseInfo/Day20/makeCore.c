// filename: makeCore.c


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int main() {
	printf("Start\n");
	abort(); // like exit() but makes a corefile
	printf("End\n");
}
