/*
 * Author: Omyaasree
 * Summary:
 * This header file defines a FIFO (First-In-First-Out) queue structure and declares functions to initialize, add, remove, and check the state of the queue. 
 The queue uses a fixed-size circular buffer with a capacity of 64 elements.
 */

#ifndef FIFO_H  // because i am including fifo.h in multiple files
#define FIFO_H

#define LEN (64)

struct FifoUll { 
    unsigned long long num[LEN]; // the data you store 
    int head; // point to just-pushed data element 
    int tail; // point to about-to-be-popped element 
    int fullness; // how many have been pushed but not yet popped 
}; 

// Function to initialize the FIFO queue.
void init(struct FifoUll *fifo);

// Function to push a new value into the FIFO queue.
int push(struct FifoUll *fifo, unsigned long long value);

// Function to pop a value from the FIFO queue. and return the value
unsigned long long pop(struct FifoUll *fifo);

// Function to check if the FIFO queue is empty.
int isEmpty(const struct FifoUll *fifo);

// Function to check if the FIFO queue is full.
int isFull(const struct FifoUll *fifo);

#endif
