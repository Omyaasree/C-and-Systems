/* constfun.c
 */

#define PI 3.141592

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int main(int argc, char** argv) {
	const double pi = 3.14159;
	/* const */ double *const dp2 = &pi;

	/* Can 'dp2' point at a different variable?
	const double e = 2.71817;
	dp2 = &e;
	*/

	// Can 'dp2' change the value of its pointed-to memory?
	*dp2 = 4.5;
	printf("%lf\n", pi);

	return 0;
}
