/*
 * Author: Omyaasree
 * Summary:
 * This file implements a simple FIFO (First-In-First-Out) queue using a circular buffer with a fixed size.
 * The queue allows pushing (adding) and popping (removing) unsigned long long integers, while checking
 * whether the queue is empty or full. Proper initialization and state tracking are maintained.
 */

#include "fifo.h"
#include <stdio.h>
#include <stdlib.h>


// defining the head tail and the number of elements in the queue
// -> to deference the pointer
void init(struct FifoUll *fifo) {
    fifo->head = 0;
    fifo->tail = 0;
    fifo->fullness = 0;
}

// method to push the number to the fifo
int push(struct FifoUll *fifo, unsigned long long num) {
    if (isFull(fifo)) {
        printf("Cannot push to the queue, it is full.\n");
        return 0; // return false 
    }
    fifo->num[fifo->head] = num;    // Add the value to the current head position in the queue
    fifo->head = (fifo->head + 1) % LEN;     // Increment the head pointer and wrap around using modulo operation
    fifo->fullness++;    // Increase the fullness count to reflect the added element

    return 1; // return true

}

unsigned long long pop(struct FifoUll *fifo) {
    if (isEmpty(fifo)) {
        printf("The queue is EMPTY, cannot remove element.\n");
        return 0; // Signal failure
    }
    
    unsigned long long num = fifo->num[fifo->tail];     // Retrieve the value at the current tail position
    fifo->tail = (fifo->tail + 1) % LEN;     // Increment the tail pointer and wrap around using modulo operation
    fifo->fullness--;    // Decrease the fullness count to reflect the removed element

    return num;
}

// Returns 1 if the queue is empty (fullness is 0), otherwise 0.
int isEmpty(const struct FifoUll *fifo) {
    return fifo->fullness == 0;
}

// Returns 1 if the queue is full (fullness equals LEN), otherwise 0.
int isFull(const struct FifoUll *fifo) {
    return fifo->fullness == LEN;
}
