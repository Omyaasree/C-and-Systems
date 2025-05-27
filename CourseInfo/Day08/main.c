#include <stdio.h>
#include "mancala.h"

int main() {
	struct Mancala board;

	init(&board);
	printf("Score: %d %d\n", board.aScoring, board.bScoring);
	return 0;
}
