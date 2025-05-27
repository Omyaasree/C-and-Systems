// Conversions.c
// Omyaasree
// this code take in hex input and converts and prints out the negative binary of the input
// submitted on 2/12/25


// #include <stdlib.h> - dont need it
#include <stdio.h> // library for standard input output
#include <math.h> // library for pow()


// METHOD for finding the length of the first argument
int findlength(char* s) {
	if (!*s) return 0;
	return 1 + findlength(s + 1);
}

//METHOD for reversing the string so that i can convert hex to dec
void reverse(char* word, int length, char* operand) {
    int j = 0;
    for (int i = length - 1; i >= 0; i--) { //working from the end of the string
        operand[j++] = word[i];
    }
    operand[length] = '\0';  // it gives a random symbol when i dont remove the leading 0
}

// METHOD to convert the hex to dec reversed to make it eazy for the 16 pows
short convert(char* word, int length, short sum) {
    for (int i = 0; i < length; i++) {

        //taking acc of both upper and lower case
    	if(word[i] == 'a' || word[i] == 'A')
    		{sum += 10 * (unsigned short)pow(16, i);}
    	else if(word[i] == 'b'|| word[i] == 'B')
    		{sum += 11 * (unsigned short)pow(16, i);}
    	else if(word[i] == 'c'|| word[i] == 'C')
    		{sum += 12 * (unsigned short)pow(16, i);}
    	else if(word[i] == 'd'|| word[i] == 'D')
    		{sum += 13 * (unsigned short)pow(16, i);}
    	else if(word[i] == 'e'|| word[i] == 'E')
    		{sum += 14 * (unsigned short)pow(16, i);}   
    	else if(word[i] == 'f'|| word[i] == 'F')
    		{sum += 15 * (unsigned short)pow(16, i);} 		
    	else 
    		{sum += (word[i] - '0') * (unsigned short)pow(16, i);}  
            // -'0' will convert the char to its actual integer value  	
    }
    short sum1 = -(short)sum; // converting unsigned short to negative value short - INSTRUCTED TO DO SO 
    
    return sum1; // returning sum1 to be converted to binary
}

// METHOD of converting short to binary
void binary(short value){
        for (int i = 15; i >= 0; i--) {
        printf("%d", (value >> i) & 1); //printing the binary
    }
    printf("\n");
}

int main(int argc, char** argv) {
    char* word = argv[1]; //original hex input as the first argument
    int length = findlength(word); //finding the length of the word to create empty arrays
    char operand[length + 1];

    //printf("Original string: %s\n", word);
    reverse(word, length, operand);

    unsigned short sum = 0; //could ve done this inside the convert method too
    short sum1 = convert(operand, length, sum);

    binary(sum1);// final calling the binary method to print out the 16 bit binary value

    return 0;
}