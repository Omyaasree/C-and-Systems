// Omyaasree
// swapends.c
// should swap all the byte reverse and print the resulting int

#include <stdio.h>

int main() {

    int input;

    while (1) { // taking in input until the end of keyboard inputs

        printf("Input: ");
        int result = scanf("%d", &input); // scanning the input and storing it to the address

        if (result == EOF) {
            break;
        }

        int output = ((input & 0xff000000) >> 24) | ((input & 0x00ff0000) >> 8) | ((input & 0x0000ff00) << 8) | ((input & 0x000000ff) << 24);
        printf("Output: %d\n", output); 

         output = ((input & 0x000000ff)) | ((input & 0x0000ff00)) | ((input & 0x00ff0000) ) | ((input & 0xff000000));
        printf("Output: %d\n", output); 

        // the & functions extract the digits from the current place and shifts it to the reversed posn
        // since we are not changing the data types we are printing the decimal value itself
    }

    // Added a message to indicate the program has terminated
    printf("Program terminated\n");
    return 0;
}
