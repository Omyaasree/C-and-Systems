/*
 * mywork.c
 *
 *  Created on: Jul 31, 2024
 *      Author: phaskell
 */

#include <stdio.h>
#include <math.h>

int main(int argc, char** argv) {
	char word[] = "zyxwvutsrq";
	char word2[5] = "ABCDEFGHIJKLMNOP";
	// char word2[] = "ABCDEFGHIJKLMNOP";
	printf("%d %c %c\n", word[6], word2[5], word2[6]);

	int arr[] = {1,2,3,4,5};
	for (int c = 0; c < 6; c++) {
		printf("%d\n", arr[c]);
	}
	
	return 0;
}
