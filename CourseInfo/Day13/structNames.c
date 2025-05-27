// filename: structNames.c
//
// Show different ways a struct can be declared.
//
// @author: phaskell


#include <stdio.h>
#include <string.h>


// Create a struct data type named "Address".
struct Address {
	int a;
	int b;
	int c;
	int d;
};


// Create an unnamed struct data type,
// and create a variable named 'nameAndAddr with that type.
struct {
	char name[64];
	char address[128];
} nameAndAddr;


// Create a struct named BikeType AND a variable
// named 'paulMountainBike' from that type.
struct BikeType {
	int numGears;
	double price;
	float size;
} paulMountainBike;



int main() {
	struct Address myAddress;

	strncpy(nameAndAddr.name, "Sparky", 64);

	paulMountainBike.numGears = 20;
	struct BikeType paulRoadBike;

	return 0;
}
