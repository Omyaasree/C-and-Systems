#include <stdio.h>

double addHalf(int x) {
	return (x + 0.5);
}

int main() {
	printf("Hello CS221\n");

	int biggest = (9 > 8 ? 9 : 8);

	printf("My value is %lf\n", addHalf(biggest));

	int a = 4;
	int b = 5;
	int c = a && b;
	printf("Value of \"boolean\" c is %d\n", c);
}
