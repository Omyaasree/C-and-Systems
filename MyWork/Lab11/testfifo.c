/*
 * Author: Omyaasree
 * Summary:
 * This program verifies the integrity of the FIFO (First-In-First-Out) queue's output.
 * It reads a file specified as a command-line argument (e.g., "fifo_output.txt"),
 * and checks if the numbers in the file match the expected sequential order starting from 1.
 * If any number is out of order, it reports a "FAIL" and exits. Otherwise, it reports "PASS".
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


int main(int argc, char *argv[]) {
    if (argc != 2) {    // Check if the required command-line argument (file name) is provided
        printf("no input file give as a cmd line prompt");
        return 0;
    }

    FILE *input = fopen(argv[1], "r"); // Open the input file in read mode

    unsigned long long expected = 1; // Start checking from the number 1
    unsigned long long actual;

    // Read each number from the file and compare it to the expected value
    while (fscanf(input, "%llu", &actual) == 1) {
        if (actual != expected) {
            printf("FAIL: Expected %llu, but found %llu.\n", expected, actual);
            fclose(input); // close the file before exiting
            return 0;
        }
        expected++; // Increment the expected value for the next number
    }

    fclose(input); // closing the input file
    printf("PASS\n"); // it comes to this line if they pass all the numbers
    return 0;
}
