// except2.cpp
//
// Show how exception HANDLING is more usefully
// done in a different method from where the
// exception is THROWN.


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string>


// A pretty boring exception class.
class NumberException { };


// Get an int from a string.
int getInt(const char* buf) {
	int retval = 0;
	int sign = 1;
	int indx = 0;

	// Skip leading spaces
	while (buf[indx] == ' ' || buf[indx] == '\t') {
		indx++;
	}

	// + or - sign?
	if (buf[indx] == '-') { sign = -1; indx++; }
	if (buf[indx] == '+') { sign = +1; indx++; }

	// Get the digits
	while (buf[indx] != 0) {
		if ('0' <= buf[indx] && buf[indx] <= '9') {
			retval *= 10;
			retval += buf[indx++] - '0';
		} else {
			// THROW the Exception here.
			throw NumberException();
		}
	}
	return retval * sign;
}


// Square an integer.
int square(int inp) { return inp*inp; }


int main() {
	char buf[256];

	while (1) {
		try {
			printf("Please enter a number\n");
			scanf("%255s", buf);
			printf("Square is %d\n", square(getInt(buf)));
		}
		// HANDLE exceptions where we get the input.
		catch (NumberException ne) {
			printf("I said a NUMBER!\n");
		}
	}

	return 0;
}
