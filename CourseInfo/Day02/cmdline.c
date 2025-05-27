#include <stdio.h>

int main(int argc, char** argv) {
	printf("I have %d args\n", argc);

	for (int c = 0; c < argc; c++) {
		printf("%s\n", argv[c]);
	}

	return 0;
}
