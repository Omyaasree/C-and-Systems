#include <stdio.h>

int main() {
	printf("%ld\n", sizeof(int));

	unsigned short w = 32768;
	short ww = (short) w;
	printf("%hd\n", ww);
	unsigned long x = 327680;
	printf("%lu\n", x);

	int million = 1000000;
	short smillion = (short) million;
	printf("%hd\n", smillion);

	short theShort = 2025;
	unsigned short bigVal = (unsigned short) theShort;
	printf("%hd\n", theShort);
	printf("%hu\n", bigVal);
	return 0;
}
