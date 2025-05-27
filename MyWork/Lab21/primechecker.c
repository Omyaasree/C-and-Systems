#include <stdio.h>  // standard input output
#include <stdlib.h>  // import for malloc and allocation stuff
#include <math.h>
#include <pthread.h>
#include <semaphore.h>  // sem_init sem_wait blah blah
#include <unistd.h>  // for usleep() command
#include "fifo.h"  // Import FIFO header

#define NUM_THREADS 8 // number of worker threads
// i tried 10 vs 9 vs 8 pure intuition

// direct copy from FIFO.c from Lab 11
// ------------------------------------------------- //
void init(struct FifoUll *fifo) {
    fifo->head = 0;
    fifo->tail = 0;
    fifo->fullness = 0;
}

int push(struct FifoUll *fifo, unsigned long long num) {
    if (isFull(fifo)) {
        printf("Cannot push to the queue, it is full.\n");
        return 0;
    }
    fifo->num[fifo->head] = num;
    fifo->head = (fifo->head + 1) % LEN;
    fifo->fullness++;
    return 1;
}

unsigned long long pop(struct FifoUll *fifo) {
    if (isEmpty(fifo)) {
        printf("The queue is EMPTY, cannot remove element.\n");
        return 0;
    }
    unsigned long long num = fifo->num[fifo->tail];
    fifo->tail = (fifo->tail + 1) % LEN;
    fifo->fullness--;
    return num;
}

int isEmpty(const struct FifoUll *fifo) {
    return fifo->fullness == 0;
}

int isFull(const struct FifoUll *fifo) {
    return fifo->fullness == LEN;
}
// --------------------------------------------
//END OF FIFO.C COPY

struct FifoUll jobQueue; // teh queue which will store the numbers

struct ResultCount {
    sem_t thread_left_alone;
    int resultCount;
} resultCount;

int total_threads = 0; // tracks the total numbers processed

pthread_mutex_t queue_lock; // to sync queue access

void checkAlgorithm(unsigned long long int NumberToCheck) {
    int found = 0;
    // manual check for 1
    if (NumberToCheck == 1) {
        printf("NOT PRIME: %llu\n", NumberToCheck);
        return;
    }
    // manual check for 2
    if (NumberToCheck == 2) {
        printf("PRIME: %llu\n", NumberToCheck);
        return;
    }
    for (int n = 2; n <= 1 + sqrt(NumberToCheck); n++) {
        if (NumberToCheck % n == 0) {
            printf("NOT PRIME: %llu %d\n", NumberToCheck, n);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("PRIME: %llu\n", NumberToCheck);
    }
}

void *worker(void *arg) {
    while (1) {
        unsigned long long number;

        pthread_mutex_lock(&queue_lock); // locking teh queue so that it doesnt get interrupted
        if (!isEmpty(&jobQueue)) { // fetches if the queue is available
            number = pop(&jobQueue);
            pthread_mutex_unlock(&queue_lock); // unlock queue
        } else {
            pthread_mutex_unlock(&queue_lock);
            usleep(10000);
            continue;
        }

        checkAlgorithm(number);

        sem_wait(&resultCount.thread_left_alone); // waits until teh threads is doen processing
        resultCount.resultCount++;
        sem_post(&resultCount.thread_left_alone); // updates result with semaphore
    }
    return NULL;
}

int main() {
    pthread_t workers[NUM_THREADS];

    // initialsie queue and semaphore and mutex
    init(&jobQueue);
    sem_init(&resultCount.thread_left_alone, 0, 1);
    resultCount.resultCount = 0;
    pthread_mutex_init(&queue_lock, NULL);

    // create worker threads
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_create(&workers[i], NULL, worker, NULL); // creates the function to exectute the function
    }

    unsigned long long number;
    while (scanf("%llu", &number) == 1) {
        while (1) {
            pthread_mutex_lock(&queue_lock);
            if (!isFull(&jobQueue)) { // teh innerloop numbers are added only when there is space in teh queue
                push(&jobQueue, number);
                pthread_mutex_unlock(&queue_lock);
                total_threads++;
                break;
            }
            pthread_mutex_unlock(&queue_lock);
            usleep(10000); // if queue is full sleep for 10 milloiseconds for the input loop
        }
    }
    while (1) {
        sem_wait(&resultCount.thread_left_alone); // waits t post the result unlike my grades the result is actually good
        if (resultCount.resultCount == total_threads) {
            sem_post(&resultCount.thread_left_alone);
            break;
        }
        sem_post(&resultCount.thread_left_alone);
        usleep(10000); // wait for the waiting loop
    }
    printf("Invalid code ending the program \n");
    return 0;
}