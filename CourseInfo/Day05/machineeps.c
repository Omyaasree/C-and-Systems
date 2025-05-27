#include <stdio.h>

int main() {
	long double eps = (long double) 1.0;
	long double prevEps = eps;

	while ((long double) (1.0 + eps) > (long double) 1.0) {
		prevEps = eps;
		eps /= 2.0;
	}

	printf("long double epsilon: %Lg\n", prevEps);
	return 0;
}
