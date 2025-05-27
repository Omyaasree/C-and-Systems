#include <stdio.h>

int main() {
	char val = -127;
	char val2 = val << 1;
	printf("%d\n", val2);

	char val3 = -31;
	char val4 = val3 >> 2;
	printf("%d\n", val4);

	unsigned char uval5 = 129;
	unsigned char uval6 = uval5 >> 2;
	printf("%u\n", uval6);

	return 0;
}
