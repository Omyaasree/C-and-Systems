// filename: strlength.c
// Write a simple string processing method, to get string length.


#include <stdio.h>
#include <string.h>


int strlength(char* input) {
	int length = 0;

	while (input[length] != 0) {
		length++;
	}
	return length;
}

int main() {
	printf("%d\n", strlength("ABCD"));
	printf("%d\n", strlen("Go Sparky!")); // use the one in the "string.h" lib

	char buf[2];
	strcpy(buf, "Go "); // doesn't fit into 'buf'
	strcat("Go ", "Dons!"); // tries to write to "constant memory"
	printf("%s\n", buf);

	return 0;
}
