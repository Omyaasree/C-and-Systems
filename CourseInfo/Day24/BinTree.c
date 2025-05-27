/* BinTree.c
 *
 * A binary tree that stores sorted strings.
 *
 * TO DO: see if this passes valgrind.
 *
 * @author: phaskell
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN (256)

struct TreeNode_t {
	char word[LEN];
	struct TreeNode_t* left;
	struct TreeNode_t* right;
};

// Show two styles of "typedef".
// Either define named struct and then typedef,
// or do both in a single step.
typedef struct TreeNode_t TreeNode;

typedef struct {
	TreeNode* root;
} Tree;


// Add a new TreeNode to the tree. The new TreeNode holds 'wordToAdd'.
// - If *ptr is NULL, the new node is added at *ptr
// - Else add 'wordToAdd' in sorted order.
void addTreeNode(TreeNode** ptr, const char* wordToAdd){
	if (wordToAdd == 0) {
		return; // we are done
	}

	// Make a new Node.
	TreeNode* newPtr = (TreeNode*) malloc(sizeof(TreeNode));
	strncpy(newPtr->word, wordToAdd, LEN);
	newPtr->left = 0;
	newPtr->right = 0;

	if (*ptr == 0) { // current node doesn't exist
		*ptr = newPtr; // add new node to list
		return;
	}

	// Add 'wordToAdd' to left or right of 'ptr'.
	if (strncmp( (*ptr)->word, wordToAdd, LEN) > 0) {
		addTreeNode( &( (*ptr)->left), wordToAdd);
	} else {
		addTreeNode( &( (*ptr)->right), wordToAdd);
	}
}


void addTree(Tree* tree, const char* wordToAdd) {
	if (tree == 0) {
		fprintf(stderr, "ERROR: tree is NULL\n");
		exit(1);
	}
	addTreeNode(&(tree->root), wordToAdd);
}


void printTree(const Tree* tree) {
	// STUDENT CODE HERE
}

void cleanTree(Tree* tree) {
	// STUDENT CODE HERE
}


int main() {
	Tree* theTree = (Tree*) malloc(sizeof(Tree));
	theTree->root = 0;

	addTree(theTree, "Monday");
	addTree(theTree, "Tuesday");
	addTree(theTree, "Wednesday");
	addTree(theTree, "Thursday");
	addTree(theTree, "Friday");
	addTree(theTree, "Saturday");
	addTree(theTree, "Sunday");

	printTree(theTree); // students write this
	cleanTree(theTree); // students write this
	return 0;
}
