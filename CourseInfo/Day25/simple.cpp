// simple.cpp
//
// Make a simple C++ class.


#include <stdio.h>
#include <string.h>


class Pet {
private:
	char petName[64];

public:
	Pet(const char* name) { strncpy(petName, name, 63); }
	const char* string() { return (char*) petName; }
};


int main() {
	int* myArray = new int[100];

	Pet cat("Rocky");
	Pet* dog = new Pet("Sparky");
	printf("My cat is %s\n", cat.string() );
	printf("My dog is %s\n", dog->string() );

	// Cleanups.
	delete dog;
	delete [] myArray;
	return 0;
}
