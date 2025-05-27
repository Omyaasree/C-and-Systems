#include <stdio.h>
#include <string.h>


char* capitalize(char* inp) {
	char* retval = inp;

	while (*inp != 0) {
		if ('a' <= *inp && *inp <= 'z') {
			*inp += 'A' - 'a';
		}
		inp++;
	}
	return retval;
}


char* decorate(char* inp) {
	char* retval = inp;

	while (*inp != 0) {
		if (*inp == ' ') {
			*inp = '*';
		}
		inp++;
	}
	return retval;
}


int main() {
	char string[64];
	strncpy(string, "Gimme a C!", 63);
	printf("%s\n", string);

	// Which function should we call?
	printf("Enter a number\n");
	int z;
	scanf("%d", &z);

	char* (*fptr)(char*) =
		(z % 2 ? capitalize : decorate);

	printf("%s\n",  fptr(string) );

	return 0;
}
