// crash.c


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int main() {
	int testNum = 2;

	switch (testNum) {
		case 1:
			int a = 0;
			int b = 15/a;
			break;
		case 2:
			char* c = (char*) 19;
			char d = *c;
			break;
	}
	return 0;
}
