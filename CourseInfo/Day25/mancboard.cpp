// mancboard.cpp


#include <stdio.h>
#include <stdlib.h>

class MancalaBoard {
private:
	int* theBoard;

public:
	MancalaBoard() : theBoard((int*) malloc(14*sizeof(int))) {
		printf("In constructor\n");
	}	
	~MancalaBoard() {
		free(theBoard);
		printf("Now in the destructor\n");
	}
};

int main() {
	MancalaBoard myBoard;
	return 0;
}
