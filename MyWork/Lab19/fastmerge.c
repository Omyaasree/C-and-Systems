/*
 * Name: Omyaasree
 * fastmerge.c - Multithreaded merge sort using 
 * POSIX threads. Limits active threads and 
 * records timing results to timing.txt.
*/

// Struct foe the array start and end 
// Merge
// SetValues
// Validate
// SortThread
// Sort
// Main

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

// #define num_threads 1

int active = 1; 
pthread_mutex_t Mutex;

typedef struct {
    int* array;
    int start;
    int end;
    int num_threads;
} ThreadArgs;


// STARTER CODE
/* Merge()
 * Inputs are two sorted subarrays: in[start..mid-1] and in[mid..end-1].
 * This function merges the subarrays, maintaining sort order.
 * The result is that 'in' is sorted from start to end-1.
 */
void Merge(int* in, int start, int mid, int end) {
    int a = start;
    int b = mid;
    int n = 0;

        // temporary storage space.
    int* tmp = (int*) malloc(sizeof(int)*(end-start));
    // Fill 'tmp' from whichever subarray has smaller "next" value.
    while (a < mid && b < end) {
        if (in[a] < in[b]) {
            tmp[n++] = in[a++];
        } else {
            tmp[n++] = in[b++];
        }
    }

    for (int i = a; i < mid; i++) {
        in[end - mid + i] = in[i];
    }
    // Now we copy the merged data to 'in'.
    for (int i = 0; i < n; i++) {
        in[i+start] = tmp[i];
    }

    // We are done with our temp storage space.
    free(tmp);
} // end Merge()

// STARTER CODE
/** Assign random integer values to all elements in
 * the provided int array.
 * @param values the array to be filled in
 * @param L number of ints in the array ("length")
 */
void setValues(int* values, const int L) {
#ifdef linux
    srand48(time(0));
#else
    srand(time(0));
#endif
    const int MaxVal = 2*L;
    for(int i = L-1; i >= 0; i--) {
#ifdef linux
        values[i] = (int) (MaxVal * drand48());
#else
        values[i] = (int) (rand() % MaxVal);
#endif
    }
}

// STARTER CODE
/** Validate that the array values are sorted in increasing order.
 * @param values the int array to validate
 * @param L number of ints in the array ("length")
 */
void validate(int* values, const int L)
{
    for(int i = L - 1; i > 0; i--) {
        if (values[i-1] > values[i]) {
            fprintf(stderr, "Sort failed\n");
            return;
        }
    }
    printf("Sort passed\n"); // prints it 10 times
} // end validate()


// This is a function is the starter for the thread entry function (SortThread). 

void* SortThread(void* args);

// This is your recursive merge sort function with threading.

// thsi is the sort method whihc will implement the merge method
void Sort(int* array, int start, int end, int num_threads) {

    if (end - start <= 1) return;

    int mid = (start + end) / 2;

    pthread_t thread;
    int createNewThread = 0;

    // I create a new thread and increment active.

    pthread_mutex_lock(&Mutex);
    if (active < num_threads) {
        active++;
        createNewThread = 1;
    }
    pthread_mutex_unlock(&Mutex);

    if (createNewThread) {

        ThreadArgs* left = malloc(sizeof(ThreadArgs));

        // Prepare arguments for the thread. We're sorting the left half (start to mid).

        left->array = array;
        left->start = start;
        left->end = mid;

        pthread_create(&thread, NULL, SortThread, left);

        //  Meanwhile, the current thread recursively sorts the right half (mid to end).

        Sort(array, mid, end, num_threads);
        pthread_join(thread, NULL);

        pthread_mutex_lock(&Mutex);
        active--;
        pthread_mutex_unlock(&Mutex);

    } else {

        Sort(array, mid, end, num_threads);

        Sort(array, start, mid, num_threads);
    }

    Merge(array, start, mid, end); // merge method call
}

void* SortThread(void* args) {
    ThreadArgs* targs = (ThreadArgs*) args;

   // Uses 1 as num_threads → This ensures no more threads will be created in this sub-sort

    Sort(targs->array, targs->start, targs->end, 1);
    free(targs);
    return NULL;
}

int main() {
    // if i dont use append and write it return the info for the 10th second 
    // so if the file already exists i am clearing it for new entry 
    FILE* clearFile = fopen("timing.txt", "w");
    if (clearFile) fclose(clearFile);

    int L = 100000;
    int* values = malloc(sizeof(int) * L);

    for (int num_threads = 1; num_threads <= 10; num_threads++) {
        setValues(values, L);
        pthread_mutex_init(&Mutex, NULL);

        clock_t start = clock();

        Sort(values, 0, L, num_threads);

        clock_t end = clock();

        pthread_mutex_destroy(&Mutex);
        validate(values, L);

        FILE* f = fopen("timing.txt", "a");
        if (f) {
            // CHANGED: Write thread count and timing to file
            fprintf(f, "%d %ld\n", num_threads, end - start);
            fclose(f);
        } else {
            fprintf(stderr, "Could not open timing.txt for writing\n");
        }
    }

    free(values);
    return 0;
}
