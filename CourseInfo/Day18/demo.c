// filename: demo.c
//
// Use a mutex to control access to the terminal screen.
//
// @author: Paul Haskell


#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>


// See below. Do we use the semaphore or not?
// #define USE_SEM


// Shared lock (global variable).
sem_t mutex;


// Two methods that share a "critical resource", the terminal screen.
void* printLetters(void* args) {
	while (1) {

#ifdef USE_SEM
		sem_wait(&mutex);
#endif

		for (char ch = 'a'; ch <= 'z'; ch++) {
			printf("%c", ch);
		}
		printf("\n");

#ifdef USE_SEM
		sem_post(&mutex);
#endif

	}
}


void* printNumbers(void* args) {
	while (1) {

#ifdef USE_SEM
		sem_wait(&mutex);
#endif

		for (char ch = '0'; ch <= '9'; ch++) {
			printf("%c", ch);
		}
		printf("\n");

#ifdef USE_SEM
		sem_post(&mutex);
#endif

	}
}


//
// main() creates several threads that share a resource.
//
int main() {
	sem_init(&mutex, 0, 1);
	pthread_t thread1, thread2;

	pthread_create(&thread1, NULL, printLetters, (void*) NULL);
	pthread_create(&thread2, NULL, printNumbers, (void*) NULL);

	// We never get here.
	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);
	printf("Both threads complete\n");

	// Final cleanups.
	sem_destroy(&mutex);
	return 0;
}
