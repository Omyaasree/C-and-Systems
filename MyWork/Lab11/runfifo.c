/*
 * Author: Omyaasree
 *
 * Summary:
 * This program tests the functionality of the FIFO (First-In-First-Out) queue. 
 * It performs 20,000 iterations of random push and pop operations. 
 * Numbers pushed to the queue are sequential, starting from 1. 
 * Popped numbers are written to a file named "fifo_output.txt". 
 * At the end, the program prints the total number of elements successfully popped.
 */

#include "fifo.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int iterator; // counter for the nunebr of iterations
    struct FifoUll fifo;
    init(&fifo); // initialise the fifo queue

    // Open the file to save the popped numbers
    FILE *output_file = fopen("fifo_output.txt", "w");
    if (!output_file) {
        printf("ERROR: Could not open file.\n");
        return 0;
    }

    unsigned long long push_number = 1; // Tracks the next number to be pushed into the queue
    int pop_count = 0;

    srand(time(NULL)); // Seed the random number generator with the current time

    for (int i = 0; i < 20000; i++) {
        iterator++;
        //printf("this the %d iteration\n", iterator);
        if(isEmpty(&fifo)){
            push(&fifo, push_number++);
            
        }else if(isFull(&fifo)){

            unsigned long long pop_number = pop(&fifo); // removing the oldest number
            fprintf(output_file, "%llu\n", pop_number); // writing to the file
            pop_count++;

        }else{
            if (rand() % 2 == 0) { // Randomly choose to push or pop from the FIFO
                push(&fifo, push_number++);
            } else {
                unsigned long long pop_number = pop(&fifo); // removing the oldest number
                fprintf(output_file, "%llu\n", pop_number); // writing to the file
                pop_count++;
                //printf("this is the %d popped element\n", pop_count);
            }
        }
    }

    //c losing the output file
    fclose(output_file);
    printf("Successfully popped %d values to fifo_output.txt\n", pop_count);
    return 0;
}
