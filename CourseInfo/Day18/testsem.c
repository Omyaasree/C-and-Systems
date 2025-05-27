// filename: testsem.c
// Create several threads, which block each other via a shared mutex.
//
// @author: Paul Haskell


#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>


// Shared lock.
sem_t mutex;


// A program with a "critical shared resource".
void* criticalThread(void* args) {
	int myArg = *((int*)args);

	printf("Starting thread %d, waiting for mutex.\n", myArg);
	sem_wait(&mutex);
	printf("\tGot the mutex for thread %d\n", myArg);

		// Critical code here!
	sleep(6);

		// Now we're done.
	printf("\tEnding thread %d, releasing mutex.\n", myArg);
	sem_post(&mutex);
}


// main() creates several threads that share a resource.
int main() {
	sem_init(&mutex, 0, 1);
	pthread_t thread1, thread2;
	int arg1 = 11, arg2 = 22;

	pthread_create(&thread1, NULL, criticalThread, (void*) &arg1);
	printf("Kicked off first thread, back in main thread.\n");
	sleep(2);

	pthread_create(&thread2, NULL, criticalThread, (void*) &arg2);
	printf("Kicked off second thread, back in main thread.\n");

	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);
	printf("Both threads complete\n");

	// Final cleanups.
	sem_destroy(&mutex);
	return 0;
}
