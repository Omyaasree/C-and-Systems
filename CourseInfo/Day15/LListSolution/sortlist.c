/* sortlist.c
 *
 * Read in text words and insert them into a Linked List,
 * in alphabetical order.
 * Skip over punctuation and numerical digits.
 * Print out the list.
 * Free all allocated memory.
 *
 * @author: Paul Haskell
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "linkedlist.h"


////
//// main() method
////
int main() {
	// Data structures
	char word[256];
	struct LinkedList theList;
	init(&theList);

	// Read words from keyboard and add to list
	while (!feof(stdin)) {
		scanf("%255s", word);
		add(&theList, word);
	}

	// Print the list and clean up.
	print(&theList);
	freeMem(&theList);
	return 0;
}

