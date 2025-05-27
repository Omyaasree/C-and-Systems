/* demo3.c
 *      Print a cool pattern.
 *      @author: phaskell
 */


//////
////// Include files
//////
#include <stdio.h>
#include <math.h>
#include <unistd.h>


//////
////// Methods
//////

/* printLine()
 * 
 * Print a line with spaces and a '*' character.
 */
void printLine(int skip) {
	for(int c = 0; c < skip; c++) {
		printf(" ");
	}
	printf("*\n");
	usleep(10000); // sleep for 0.1 seconds
	fflush(stdout); // flush the printed output
}


//////
////// Main module
//////
int main(int argc, char** argv) {
	double counter = 0.0;
	while (1) {
		printLine(40 + 40*sin(counter));
		counter += 0.07;
	}
	return 0;
}
