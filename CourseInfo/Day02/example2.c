/* mywork.c
 */

#include <stdio.h>
#include <math.h>


// Calculate 1 - 1/2 + 1/3 - 1/4 + 1/5 - ...
double calcLimit() {
	double cur = 1.0;
	double prev = 2.0;
	int indx = 2;
	while (fabs(cur-prev) > 1.0e-6) {
		prev = cur;
		cur -= pow(-1.0, indx)/indx;
		indx++;
	}
	return cur;
}


int main(int argc, char** argv) {
	printf("%lf %lf\n", calcLimit(), log(2.0));
	
	return 76;
}
