/* typed.c
 *
 * Show off several "typedefs".
 *
 * @author: phaskell
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// unsigned char byte;
typedef unsigned char byte;

typedef char checkerBoard[8][8];

// Two ways to 'typedef' a struct.
// Both "Flavor" and "AlsoFlavor" are created via typedef.
typedef struct IceCreamFlavor {
	char name[64];
	float price;
} Flavor;

typedef struct IceCreamFlavor AlsoFlavor;

int main(int argc, char** argv) {
	byte secretKey;
	checkerBoard myBoard;
	myBoard[2][1] = 'O';

	struct IceCreamFlavor chocolate;
	Flavor berry;
	AlsoFlavor mint;
	strncpy(chocolate.name, "chocolate", 64);
}
