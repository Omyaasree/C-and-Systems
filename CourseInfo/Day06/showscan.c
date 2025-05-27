// filename: showscan.c
// Show how scanf() works.


#include <stdio.h>

int main() {
	double myId;
	char myName[128];
	printf("Enter a double and a string\n");
	scanf("%lf %s", &myId, myName); // no '&' to scan a string
	printf("%lf %s\n", myId, myName);

	return 0;
}

