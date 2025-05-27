#include <stdio.h>

int counter = 10;

void countdown() {
	printf("%d\n", counter);
	counter--;
	if (counter <= 0) {
		printf("Blastoff!\n");
	}
}


int main() {
	for (int i = 0; i < 10; i++) {
		countdown();
	}
}
