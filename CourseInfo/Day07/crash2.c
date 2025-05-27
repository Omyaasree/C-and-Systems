/* crash2.c
 *
 * Compile and run this on command line.
 * It will crash.
 */


#include <stdio.h>


int main(int argc, char** argv) {
	char* someText = "Here is a nice, long line of text. Hey, longer!";
	someText[0] = 'h';
	return 0;
}
