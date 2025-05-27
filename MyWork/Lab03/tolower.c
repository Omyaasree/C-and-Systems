// Omyaasree Balaji 
// Submission : toLower.c
// this code randomizes the initial array for each srand value 
// does not use time null 

#include <stdio.h>
#include <stdlib.h>

//C uses top-down approach unlike java??!!??!!
//recursion to find the length of each cmd argument

// mehtod to find out the length of the argument to create an array to lower it later
int findlength(char* s) {
	if (!*s) return 0;
	return 1 + findlength(s + 1);
}

// method to lower the uppercases
void lower(char* word, int length) {
	//printf("check1 \n");
	for(int j = 0 ; j < length ; j++){
		char val = word[j];
		if(65 <= val && val <= 90){ // the uppercase range is only from 65 to 90 
			val = val + 'a' - 'A'; // changing the uppercase to lowercase
		}
		printf("%c" , val); //print all the things same except changes uppercase to lowercase 
	}
}

int main(int argc, char** argv) {
	int no_arguments = argc - 1; 
	// the first arg[0] is the name of the file or code 
	//printf("the number of arguments is %d \n", no_arguments);  // to print out the number of arguments

	for (int i = 1 ; i < argc ; i++){
		int length = findlength(argv[i]);
		lower(argv[i], length);
		printf(" ");

	}
}
