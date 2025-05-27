// Omyaasree Balaji
// logger.c 
// this code reads single lines froma text file and updates the current time and prints the text line after it. 

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h> // for the strlen of the buf for the length of each text line

void readLine(FILE* file1) {

	char* buf = (char*) malloc(1000); // allocating a large space of memory to store the line read by the file reader
    int isLastLine = 0; // check for last line of the file 

    while (fgets(buf, 1000, file1) != NULL) { // fgets() method to read each line of the file input 

        // checking if end of file then return true
        if (feof(file1)) {
            isLastLine = 1;
        }

        for (int i = 0; i < strlen(buf); i++) { // for the length of the line read checking for the new line char
            // checking for the end of file line because it leaves an extra line space if that condition is not there
            if (buf[i] == '\n' && isLastLine) {
                buf[i] = '\0'; // replacing the new line string with the null terminator
            }
        }

        time_t curr_time;
        time(&curr_time);
        char* time_str = ctime(&curr_time);
        time_str[strlen(time_str) - 1] = '\0'; // removing the last new line char from the ctime() method and replacing it with \0
        printf("%s %s", time_str, buf); // printing the time and the text line from the file input 

    }
    free(buf); // freeing the allocated memory
}

int main(int argc , char** argv){

    // case for when the file is not given in the command line 
    if(argc < 2){
        printf("there is no input file given");
        exit(0);
    }
    
    FILE* file1 = fopen(argv[1], "r");

    // case for when the input file does not exist
    if(file1 == NULL){
        printf("the given file does not exist");
    }

	readLine(file1); // the method for reading lines and printing the time along side
	fclose(file1); // closing the opened file
	return 0;

}