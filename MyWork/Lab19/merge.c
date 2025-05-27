/***********************************************************************
 * file:  MergeSort
 *
 * Implement and test MergeSort.
 * MergeSort is O(n log n) in computation, and O(n) in storage.
 * And it's a cool algorithm!
 *
 * @author phaskell
 **********************************************************************/


//////
////// Includes
//////
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

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

	// We must handle not-yet-merged elements in 'a' or 'b',
	// and we must copy merged data from 'tmp' to 'in'.
	// It would be simple to copy remaining unmerged elements
	// to the end of 'tmp' and then to copy all of 'tmp'
	// to in, but let's do this more efficiently.
	//
	// At this point, either the 'a' subarray or 'b' subarray is empty
	// (or both are empty).  If the 'b' subarray is not empty,
	// its largest elements are already at the end of 'in',
	// and we can just copy the "merged" elements to the start of 'in'.
	// If the 'a' subarray is not empty, then the 'b' subarray IS empty.
	// We can copy unmerged data from 'a' to the end of 'in',
	// and then copy the "merged" data.

	// Copy unmerged 'a' data (if any) to end of 'in'.
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


/* Sort()
 *
 * The Merge function is just a helper.
 * This function does actual sorting, recursively.
 * Each invocation sorts a PORTION of the array:
 *	indices [start, end-1].
 *
 * @param in - input int array to be sorted
 * @param start - index of starting subarray to sort
 * @param end - index of the end of the subarray to sort
 * (one past the index of the end)
 */
void Sort(int* in, int start, int end) {
	if (end - start == 2) {
		// if 2 elements out of order, swap them
		if (in[start+1] < in[start]) {
			int tmp = in[start];
			in[start] = in[start+1];
			in[start+1] = tmp;
		} // else this subarray is already in order

	} else if (end - start > 2) { // recursive!
		int split = (end + start)/2;
		Sort(in, start, split);
		Sort(in, split, end);
			// After merge, our subarray will be sorted.
		Merge(in, start, split, end);

	} else if (end - start < 1) {
		fprintf(stderr, "Sort() ERROR: empty array");
	}
	// else if (end - start < 2) { do nothing }
} // end Sort()



int main() {
	// Generate test data
	const int NumVals = 10000000;
	int* testData = (int*) malloc(sizeof(int)*NumVals);
	setValues(testData, NumVals);

	// Sort the random data.
	Sort(testData, 0, NumVals);

	// Verify the data are sorted.
	validate(testData, NumVals);

} // end main()

