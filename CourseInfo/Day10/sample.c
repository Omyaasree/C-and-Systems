// sample.c
//
// Show how to emulate a 2-d array with a 1-d array
//
// @author: phaskell


#include <stdio.h>
#include <stdlib.h>

char getValue(char* board, int row, int col) {
	return board[row*8 + col];
}

char* setValue(char* board, int row, int col) {
	return board + row*8 + col;
	return &(board[row*8 + col]);
}

int main() {
	char* checkers = (char*) malloc(64);
	*(setValue(checkers, 3, 5)) = 'X';
	printf("%c\n", getValue(checkers, 3, 5));
	return 0;
}
