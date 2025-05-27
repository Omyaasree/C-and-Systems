// filename: structcode.c


#include <stdio.h>


// Make our own struct
struct Book {
	char title[128];
	char author[128];
	int numPages;
};


int main() {
	struct Book catInTheHat;
	// catInTheHat.title = "Cat in the Hat";
	// catInTheHat.author = "Dr. Seuss";
	catInTheHat.numPages = 23;

	struct Book dasKapital;
	// dasKapital = "Capital";
	// dasKapital.author = "Karl Marx";
	dasKapital.numPages = 440;

	long double bigNum = 1.0;
	printf("size of float: %ld\n", sizeof(float));
	printf("size of double: %ld\n", sizeof(double));
	printf("size of long double: %ld\n", sizeof(bigNum));

	for (int i = 0; i < 9000; i++) {
		printf("%Lg\n", bigNum);
		bigNum *= 2.0;
	}

	return 0;
}

