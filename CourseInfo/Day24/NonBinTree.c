/* NonBinTree.c
 *
 * A nonbinary tree that stores taxonomy of animals.
 *
 * TO DO: see if this passes valgrind.
 *
 * @author: phaskell
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct TreeNode_t {
	char word[256];
	int depth;
	struct TreeNode_t* nextSib;
	struct TreeNode_t* firstChild;
};

// Show two styles of "typedef".
// Either define named struct and then typedef,
// or do both in a single step.
typedef struct TreeNode_t TreeNode;

typedef struct {
	TreeNode* root;
} Tree;


// Given a string of the form "first:second:third:fourth...",
// the "subject word" is "first".
// subjcmp() returns 0 if the two strings' "subjects" match,
// and returns nonzero otherwise.
int subjcmp(const char* a, const char* b) {
	char* result1 = strchr(a, ':');
	int l1 = strlen(a);
	if (result1 != 0){
		l1 = result1 - a;
	}
	char* result2 = strchr(b, ':');
	int l2 = strlen(b);
	if (result2 != 0) {
		l2 = result2 - b;
	}
	if (l1 != l2) {
		return 1; // different lengths
	}
	return strncmp(a, b, l1);
}

// Given 'inp' of the form "first:second:third:fourth..."
// copy "first" to 'ptr'.
// If there is no ':' in 'inp', copy the whole string.
void subjcpy(char* ptr, const char* inp) {
	char* r1 = strchr(inp, ':');
	if (r1 == 0) {
		strncpy(ptr, inp, 256); // copy whole word
	} else {
		int result = r1 - inp;
		strncpy(ptr, inp, result);
	}
}

// Given a string of the form "first:second:third:fourth..."
// return "second:third:fourth..."
// return 0 if no ':' is found in the string.
const char* getPredicate(const char* inp) {
	char* result = strchr(inp, ':');
	if (result != 0) {
		return result + 1; // skip over the ':'
	}
	return (char*) 0;
}


// Add a new TreeNode to the tree. The new TreeNode holds 'wordToAdd'.
// - If *ptr is NULL, the new node is added at *ptr
// - If the "subjects" of wordToMatch and *ptr or a sibling of *ptr match,
//   add the new node as a child of the matched node (and keep looking for matches recursively)
// - Else subjects do not match--add the new node as a sibling of *ptr
void addTreeNode(TreeNode** ptr, const char* wordToAdd){
	if (wordToAdd == 0) {
		return; // we are done
	}

	if (*ptr == 0) { // current node doesn't exist
		TreeNode* newPtr = (TreeNode*) malloc(sizeof(TreeNode));
		subjcpy(newPtr->word, wordToAdd);
		newPtr->firstChild = 0;
		newPtr->nextSib = 0;
		*ptr = newPtr; // add new node to list
		wordToAdd = getPredicate(wordToAdd);
		addTreeNode( &(newPtr->firstChild), wordToAdd); // try to add rest of wordToAdd to the matching node
		return;
	}

	// Walk sibling-list looking for matching subject.
	TreeNode* listPtr = *ptr;
	while (listPtr->nextSib != 0 && subjcmp(listPtr->word, wordToAdd) != 0) {
		listPtr = listPtr->nextSib;
	}
	// Either we found a match or we found end of the list.
	if (subjcmp(listPtr->word, wordToAdd) == 0) { // found match!
		wordToAdd = getPredicate(wordToAdd);
		addTreeNode( &(listPtr->firstChild), wordToAdd); // try to add rest of wordToAdd to the matching node
 	} else { // add new node to this sibling-list
		TreeNode* newPtr = (TreeNode*) malloc(sizeof(TreeNode));
		subjcpy(newPtr->word, wordToAdd);
		newPtr->firstChild = 0;
		newPtr->nextSib = 0;
		listPtr->nextSib = newPtr; // add new node to list
		wordToAdd = getPredicate(wordToAdd);
		addTreeNode( &(newPtr->firstChild), wordToAdd); // try to add rest of wordToAdd to the new node
 	}
}


void addTree(Tree* tree, const char* wordToAdd) {
	if (tree == 0) {
		fprintf(stderr, "ERROR: tree is NULL\n");
		exit(1);
	}
	addTreeNode(&(tree->root), wordToAdd);
}

// Print requested number of spaces: use in printTree()
void pad(int i) {
	while (i-- > 0) {
		printf(" ");
	}
}

void printTree(const Tree* tree) {
// ADD CODE HERE
}

void cleanTree(Tree* tree) {
// ADD CODE HERE
}


int main() {
	Tree* theTree = (Tree*) malloc(sizeof(Tree));
	addTree(theTree, "Mammal:Felid:Panther");
	addTree(theTree, "Reptile:Lizard:Gecko");
	addTree(theTree, "Mammal:Felid:Tiger");
	addTree(theTree, "Reptile:Snake:Rattlesnake");
	addTree(theTree, "Mammal:Felid:Panther:Puma");
	addTree(theTree, "Reptile:Snake:Garter snake");
	addTree(theTree, "Insect:Ant:Honey Ant");
	addTree(theTree, "Mammal:Canid:Wolf");
	addTree(theTree, "Mammal:Felid:Housecat");
	addTree(theTree, "Mammal:Canid:Coyote");
	addTree(theTree, "Reptile:Snake:Sidewinder");
	addTree(theTree, "Reptile:Snake:Sidewinder");
	printTree(theTree); // students write this
	cleanTree(theTree); // students write this
	return 0;
}
