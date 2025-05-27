// Omyaasree
// Lab02
// gituser code
// this code takes in a predefined string 
// then adds up the ascii values of each char in that string

#include <stdio.h>

//method to add up the ascii values of each char in the string passed
int change(char username[]){
	int counter = 0; //to move through the string 
	int result = 0; //to add the ascii values 

	// apparently for loop doesnt work here
	// because there is no method to check the length of the string without import of string.h
	while (username[counter] != 0){ 
		result += username[counter]; //adding asscii values to the result
		counter++; // to move through the word
	}
	return result;
}

int main() {
	// Your main() method should call this method with your GitHubId string 
	// and should print out the resulting integer, with no other text
	char str[9]; //pre defining a string 
	char username[] = "Omyaasree"; //github user name case sensitive
	int result = change(username); //gettign the result
	printf("%d" , result); // printing the result only without text or spaces
}