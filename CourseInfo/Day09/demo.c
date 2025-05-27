// demo.c
//
// Show how ctime() works
//
// @author: phaskell


#include <stdio.h>
#include <time.h>

int main() {
	time_t now;
	time(&now);
	printf("The time is %s\n", ctime(&now) );
	return 0;
}
