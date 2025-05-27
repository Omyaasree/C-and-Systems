// sorting.c
//


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


// Compare strings by the number of commas they have :)
int compareStrings(const void* voidA, const void* voidB) {
	const char* a = *((const char**) voidA);
	const char* b = *((const char**) voidB);

	// Count number of commas in each string.
	int numA = 0;
	while (*a != 0) {
		if (*a == ',') { numA++; }
		a++;
	}
	int numB = 0;
	while (*b != 0) {
		if (*b == ',') { numB++; }
		b++;
	}

	// Use the "compare" rules for return value.
	if (numA > numB) { return 1; }
	if (numA < numB) { return -1; }
	return 0;
}


// Some sample data.
char* strings[6] = {
"The quick, brown fox jumps over the lazy dog",
"Hit the road, Jack, and dontcha come back no more, no more, no more, no more",
"Vodka martini, shaken, not stirred",
"Tis a far, far better thing I do now than I have ever done before",
"Beware the Jabberwock, my son, the jaws that bite, the claws that snatch",
"We the people, in order to form a more perfect union, establish justice"
};


// Main module
int main() {
	// Sort our strings
	qsort(strings, 6, sizeof(char*), compareStrings);

	// And print them out
	for (int n = 0; n < 6; n++) {
		printf("%s\n", strings[n]);
	}

	return 0;
}
