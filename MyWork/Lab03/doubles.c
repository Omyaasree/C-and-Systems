// Omyaasree
// Doubles.c
// this converts doubles in the command line argument to a short 

#include <stdio.h> //library for std input output
#include <stdlib.h> //library for std libr

int main(int argc , char **argv) {

	//checking if there are enough cmd args
	if(argc < 2){ 
	
		printf("no command line arguments provided");
		//the name of the file is considered 1 argument in C

	}else {

		for(int i = 1 ; i < argc ; i++){
			//double check = atof(argv[i]); //atof() converts the string to a double
			short checker = (short) atof(argv[i]); //casting short to a double
			printf("%d\n", checker);
		}
	}
}
