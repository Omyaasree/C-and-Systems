// filename: linkedlist.h
// @author: Paul Haskell


#ifndef LLIST_H
#define LLIST_H


// LinkedList structs:  node and list
struct entry {
	char word[256];
	struct entry* next;
};

struct LinkedList {
	// Declare data structures for a Linked List
	// of strings.
	struct entry* head;
};


// LinkedList methods
void init(struct LinkedList* ll);
void add(struct LinkedList* ll, char* theWord);
void print(struct LinkedList* ll);


#endif // #ifndef LLIST_H
