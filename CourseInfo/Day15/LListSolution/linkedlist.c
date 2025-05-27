// filename: linkedlist.c
// @author: Paul Haskell


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
// destructor - free all memory allocated by a list
void init(struct LinkedList* ll) {
	ll->head = (struct entry*) 0;
}

void add(struct LinkedList* ll, char* theWord) {
	cleanWord(theWord);

	// Make entry for the new word.
	// May have to free it if word is already in the list.
	struct entry* thisEntry = (struct entry*) malloc(sizeof(struct entry));
	strncpy(thisEntry->word, theWord, 255);
	thisEntry->next = (struct entry*) 0;

	// Is the list empty?
	if (ll->head == (struct entry*) 0) {
		ll->head = thisEntry;
		return;
	}

	// Does theWord come before the current head?
	if (compare(ll->head->word, theWord) > 0) {
		thisEntry->next = ll->head;
		ll->head = thisEntry;
		return;
	}

	// Does theWord match the current head?
	if (compare(ll->head->word, theWord) == 0) {
		free(thisEntry);
		return;
	}

	// theWord comes after head.
	// Traverse the list to find where it belongs.
	struct entry* ptr = ll->head;
	while (ptr->next != (struct entry*) 0 &&
			compare(ptr->next->word, theWord) < 0) {
		ptr = ptr->next;
	}

	// Is theWord already in our list?
	if (ptr->next != (struct entry*) 0 &&
			compare(ptr->next->word, theWord) == 0) {
		free(thisEntry);
		return;
	}

	// Either ptr->word is before theWord and ptr->next->word is after
	// theWord, or ptr->word is before theWord and ptr->next is NULL.
	// Either way, add thisEntry after ptr and before ptr->next
	thisEntry->next = ptr->next;
	ptr->next = thisEntry;
}


void print(struct LinkedList* ll) {
	struct entry* ptr = ll->head;
	while (ptr != (struct entry*) 0) {
		printf("%s ", ptr->word);
		ptr = ptr->next;
	}
	printf("\n");
}


void freeMem(struct LinkedList* ll) {
	struct entry* ptr = ll->head;
	while (ptr != (struct entry*) 0) {
		struct entry* prev = ptr;
		ptr = ptr->next;
		free(prev);
	}
}

