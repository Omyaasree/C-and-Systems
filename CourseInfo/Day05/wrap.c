#include <stdio.h>

int main() {

	unsigned bits = 5;
	unsigned counter = 0;
	while (1) {
		printf("%d\n", counter);
		counter = (counter+1) & ((1<<bits)-1);
	}
	return 0;
}
