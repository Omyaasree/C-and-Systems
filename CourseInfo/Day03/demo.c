// filename:  demo.c
// @author: phaskell
// Defines some methods, shows a 'struct'


#include <stdio.h>
#include "demo.h"


// DEFINE the already-declared variable.
float myGlobal = 12.345;


// DEFINE the already-declared method.
void theMethod() {
	const int nonStatic = PizzaCost;
	static int yesStatic = 20;

	// nonStatic += 1;
	yesStatic += 1;
	printf("%d %d\n", nonStatic, yesStatic);
}


int main(int argc, char** argv) {
	struct PlayingCard aceOfSpades;
	aceOfSpades.value = 14;
	aceOfSpades.suit = 'S';

	myGlobal += 1.0;

	printf("%f\n", myGlobal);

	printf("How many command line args? %d\n", argc);
	for (int num = 0; num < argc; num++) {
		printf("%s\n", argv[num]);
	}

	for (int count = 0; count < 10; count++) {
		theMethod();
	}
}

