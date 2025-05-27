/*
Author: Omyaasree
Summary:
This program tests memory access performance. It allocates a buffer and measures the time taken to write to a large number ("Big") and a small number ("Small") of
random memory locations. 
The elapsed times are recorded and saved in "memspeed.txt" for analysis.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double big(char *buffer_pointer, size_t using, size_t num_pointers){

	char **char_pointers = (char **)malloc(num_pointers * sizeof(char *)); // allocating the memory for the big aray 

	// for loop to enter the random numbers in the array
	for (size_t i = 0; i < num_pointers; i++) {
		char_pointers[i] = buffer_pointer + (rand() % using);
	}

	clock_t start_time = clock(); // clock start time

	for (size_t i = 0; i < num_pointers; i++) {
		*char_pointers[i] = (char)1;
	}

	clock_t end_time = clock(); // clock end time

	double elapsed_time = ((double)(end_time - start_time) * 1000); // calculating the time difference
	printf("Big: %ld\n", (long)elapsed_time);

	free(char_pointers); // freeing the allocated memory
	return elapsed_time;
}

double small(char *buffer_pointer, size_t using, size_t num_pointers){

	char **char_pointers = (char **)malloc(num_pointers * sizeof(char *)); // allocating the memory for the small array 

	// for loop to enter the random numbers in the array
	for (size_t i = 0; i < num_pointers; i++) {
		char_pointers[i] = buffer_pointer + (rand() % using);
	}

	clock_t start_time = clock(); // clock start time

	for (size_t i = 0; i < num_pointers; i++) {
		*char_pointers[i] = (char)1;
	}

	clock_t end_time = clock(); // clock end time
 
	double elapsed_time = ((double)(end_time - start_time)*1000) ; // calculating the time difference
	printf("Small: %ld\n", (long)elapsed_time);

	free(char_pointers); // freeing the allocated memory
	return elapsed_time;
}

int main(){

	size_t buffer_size = 10; // start by allocating the small buffer
	void *buffer_pointer = NULL;

	// double and free the pointer until the value is null
	while((buffer_pointer = malloc(buffer_size)) != NULL){
		free(buffer_pointer);
		buffer_size *=2;
	}

	buffer_size /= 2; // the previous calue of the buffer before it becomes null

	//printf("maximum allocated memory is %d\n" , buffer_size); // test to find the mem allocated

	size_t using = (3*(buffer_size)/4); // Now, allocate a buffer approximately ¾ of the maximum possible size. 
	buffer_pointer = (char*) malloc(using);

	srand((unsigned int)time(NULL)); // setting the seed value for the random

	double elapsed_time_big = big(buffer_pointer, using, 1000000);
	double elapsed_time_small = small(buffer_pointer, using, 1000);

	FILE *file = fopen("memspeed.txt", "w"); // file for the output
	if (file) {
		// writing to the file 
		fprintf(file, "Big: %ld\n", (long)elapsed_time_big);
		fprintf(file, "Small: %ld\n", (long)elapsed_time_small);
		fclose(file);
	} else {
		fprintf(stderr, "Error opening file!\n"); // if file not found
	}

	free(buffer_pointer); // freeing the pointer

	return 0;
}
