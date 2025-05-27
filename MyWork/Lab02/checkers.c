#include <stdio.h> //library for the input output

int main() {

	//variable for the counter: needed for the patter of X AND O 
	int counter = 0;
	
	for (int i = 0 ; i < 8; i ++){
		for(int j = 0 ; j < 8; j ++){
			if (counter % 2 == 0){
				printf("X");
			} else {
				printf("O");
			}
			counter++; // flips between X and O
		}
		printf("\n"); // new line for every 8 chars
		counter ++; // 2 coincident lines dont start with the same letter
	}
}