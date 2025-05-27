// Omyaasree Balaji 
// Submission : shuffle.c
// this code randomizes the initial array for each srand value 
// does not use time null 

#include <stdio.h>
#include <stdlib.h> // library for rand() and srand()

int main(int argc ,char** argv){

	int range = atoi(argv[1]); // converting string arg 1 to int value
	srand(1243); //long value for srand
	int arr[range]; //empty array with number of elements equal to arg 1

	printf("original array\n");

	for(int i = 0; i < range; i++ ){
		arr[i] = i;
		printf("%d" ,arr[i]);
	} //original array with 0 to N-1 elements

	for(int i = 0; i < range; i++ ){
		int j = rand() % range;
		int temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
	} // rand() to randomize the value 
	// it doesnt randomize more than 1 time for each srand long value

	printf("\nfinal random \n");

	for(int i = 0; i < range; i++ ){
		printf("%d" ,arr[i]);
	}

	// printing the final random array

}
