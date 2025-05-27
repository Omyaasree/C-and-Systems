/* helper.h
 *
 * Helper functions for sorting.
 * @author: phaskell
 */

#ifndef HELPER_H_
#define HELPER_H_


/** Assigns random integer values to all elements in
 * the provided int array.
 * @param values the array to be filled in
 * @param L the number of ints in the array ("length")
 */
void setValues(int* values, const int L);


/** Validates that the input values are sorted in increasing order.
 * @param values the int array to validate
 * @param L the number of ints in the array ("length")
 */
void validate(int* values, const int L);


#endif /* HELPER_H_ */
