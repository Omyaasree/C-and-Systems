// filename: demoTime.c


#include <stdio.h>
#include <time.h>

int main() {
	unsigned long start = clock();

	time_t now = time(0);
	printf("%s\n", ctime(&now));

	unsigned long end = clock();

	printf("%ld\n", end - start );
	printf("CLOCKS_PER_SEC: %ld\n", CLOCKS_PER_SEC);
	
	return 0;
}
