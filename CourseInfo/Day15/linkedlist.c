// filename: linkedlist.c
// @author: ???


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include "linkedlist.h"


// 'Skip over' first char in a string,
// by copying subsequent chars over it.
static void skipChar(char* word) {
	while (*word != 0) {
		*word = word[1];
		word++;
	}
}


// Clean a string: convert to lowercase,
// remove punctuation and numerical digits.
static void cleanWord(char* word) {
	char* cur = word;
	while (*cur != 0) {
		// Convert to lowercase.
		if ('A' <= *cur && *cur <= 'Z') {
			*cur += 'a' - 'A';
		}
		// Clean punctuation, digits, etc.
		if (*cur < 'a' || *cur > 'z') {
			skipChar(cur);
		}
		if ('a' <= *cur && *cur <= 'z') {
			cur++;
		} // else skip it the next time thru the loop
	}
}

// Compare two strings in alphabetical order:
// -1 if first is smaller
//  0 if both are equal
// +1 if first is larger
static int compare(char* first, char* second) {
	while (1) {
		if (*first < *second) { return -1; }
		if (*first > *second) { return 1; }
		if (*first == 0) { return 0; } // *second must be 0 also
		first++;
		second++;
	}
	return 0;
}


// Linked List methods:
// init() - initialize a list
// add() - add an entry to the list, in alphabetical order
// print() - print the entire list
void init(struct LinkedList* ll) {
	ll->head = (struct entry*) 0;
}

void add(struct LinkedList* ll, char* theWord) {
	cleanWord(theWord);

	// Make entry for the new word.
	struct entry* thisEntry = (struct entry*) malloc(sizeof(struct entry));
	strncpy(thisEntry->word, theWord, 256);
	thisEntry->next = (struct entry*) 0;

	// Is the list empty?
	// FILL IN CODE HERE!
	if(thisEntry == null){
		thisEntry -> word;
		thisEntry++;
	}

	int x = compare(thisEntry, word);

	// Does theWord come before the current head?
	// FILL IN CODE HERE!
	if(x == -1){
		temp = thisEntry;
		thisEntry == word;
		thisEntry++;
		thisEntry = temp;
	}

	// Does theWord match the current head?
	// FILL IN CODE HERE!
	if(x == 0){
		continue;
	}

	// theWord comes after head.
	// Traverse the list to find where it belongs.
	// FILL IN CODE HERE!
	for(int i = 0 ; i < )
	if(x == 1){
		thisEntry++;
		thisEntry = word;
	}

	// Is theWord already in our list?
	// FILL IN CODE HERE!



	// theWord is not in our list. Insert it properly.
	// FILL IN CODE HERE!
}


void print(struct LinkedList* ll) {
	// FILL IN CODE HERE!
}


