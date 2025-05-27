// filename: mempool.c
// Manage a SHARED memory pool safely, with a mutex.
//
// @author: Paul Haskell


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <pthread.h>
#include <semaphore.h>
#include <errno.h>


// Memory pool
typedef struct {
	sem_t mutex; // Shared lock.
	char* buffers[10]; // the shared memory buffers
	int bufIsFree[10]; // is each buffer free or in use?
} MemPool;

// Initialize a memory pool.
void init(MemPool* mp) {
	sem_init( &(mp->mutex), 0, 1);
	for (int i = 0; i < 10; i++) {
		mp->bufIsFree[i] = 1;
		mp->buffers[i] = malloc(1000000);
	}
}

// Get a free buffer.
//
// If none is available, release mutex and wait
// for a fraction of a second, and keep trying.
char* get(MemPool* mp) {
	char* retval = 0;
	do {
		sem_wait(&(mp->mutex));
		for (int i = 0; i < 10; i++) {
			if (mp->bufIsFree[i]) {
				retval = mp->buffers[i];
				mp->bufIsFree[i] = 0;
				// printf("Getting %d\n", i);fflush(stdout);
				break;
			}
		}
		sem_post(&(mp->mutex));

		// Are we safe here, outside of mutex protection?
		// YES: we are not changing any SHARED resources here.

		// Have a buffer?
		if (retval != 0) { return retval; }

		// No buffer available: wait and try again.
		printf("."); fflush(stdout);
		usleep((unsigned) (1000000*drand48()) );
	} while (retval == 0);
}

// Return a memory buffer to the pool.
void put(MemPool* mp, char* ptr) {
	sem_wait(&(mp->mutex));
	int i = 0;
	for (i = 0; i < 10; i++) {
		if (mp->buffers[i] == ptr) {
			mp->bufIsFree[i] = 1;
			// printf("Putting %d\n", i);fflush(stdout);
			break;
		}
	}
	sem_post(&(mp->mutex));
	if (i == 10) {
		printf("ERROR: someone put a buffer not in the pool\n");
	}
}


// A process that consumes and frees memory from the pool.
void* memUser(void* args) {
	// Our shared memory pool.
	MemPool* mp = (MemPool*) args;

	while (1) {

		// Get memory for our important work.
		char* ptr = get(mp);
		if (ptr == 0) { // did we get a valid buffer?
			printf("FAILURE: got NULL mem buf\n");
			break;
		}

		// Do our important work :)
		usleep((unsigned) (1000000*drand48()));

		// Work is done--release our memory.
		put(mp, ptr);
	}
}


// Main: exercise the memory pool.
int main() {
	// Setup
		// Make and initialize a memory pool
	MemPool pool;
	init(&pool);
		// Initialize random generator
	srand48(time(0));
		// Make 11 threads.
	const int NumThreads = 11;
	pthread_t threads[NumThreads];

	// Kick off the threads, all sharing a single memory pool.
	printf("Starting thread creation\n");fflush(stdout);
	for (int t = 0; t < NumThreads; t++) {
		pthread_create(&(threads[t]), NULL, memUser, (void*) &pool);
	}

	// Wait for the (hopefully never-ending) threads.
	void* retval;
	for (int t = 0; t < NumThreads; t++) {
		pthread_join(threads[t], &retval);
	}

	// Final cleanups.
	printf("Threads finished?!?\n"); fflush(stdout);
	return 0;
}
