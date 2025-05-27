// demo.c
//
// Demonstrate creation of a parallel thread.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>


void* printTwenty(void* inp) {
	long start = (long) inp;
	long i;
	for (i = start; i < start + 20; i++) {
		printf("%ld\n", i);
		usleep(100000);
	}
	return (void*) i;
}


int main() {
	// Run printTwenty() in separate thread.
	pthread_t helpThread;
	long start1 = 100;
	pthread_create(&helpThread, NULL, printTwenty, (void*) start1);

	// Run printTwenty() in main thread also!
	long start2 = 200;
	const long mainRetval = (const long) printTwenty((void*) start2);

	// Wait for helpThread to finish.
	long threadRetval; // holds return value from 'helpThread'
	pthread_join(helpThread, (void**) &threadRetval);
	printf("Thread ended at value: %ld\n", threadRetval);

	long start = 300;

	// Finish up.
	printf("Main ended at value: %ld\n", mainRetval);
	return 0;
}
