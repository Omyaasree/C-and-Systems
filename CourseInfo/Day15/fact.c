// fact.c
//
// calcualate factorials using recursion
//
// @author: phaskell


#include <stdio.h>

long long fact(long long n) {
	// "base case"
	if (n < 2) { return 1; }

	return n * fact(n-1);
}

int main() {
	printf("%lld\n", fact(20));

	return 0;
}
