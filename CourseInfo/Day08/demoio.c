// filename: demoio.c
//
// Show low-level I/O, with LOTS of error checking.
//
// @author: phaskell


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


int main() {
	int fd = open("somedoubles", O_CREAT | O_RDWR);
	if (fd < 0) {
		printf("Error opening file\n");
		return 1;
	} else {
		printf("Our file descriptor is %d\n", fd);
	}

	double pi = 3.14159;
	double e = 2.71817;
	double avo = 6.02e23;

	if (write(fd, &pi, sizeof(double)) != sizeof(double)) {
		printf("Problem writing\n");
	}
	if (write(fd, &e, sizeof(double)) != sizeof(double)) {
		printf("Problem writing\n");
	}
	if (write(fd, &avo, sizeof(double)) != sizeof(double)) {
		printf("Problem writing\n");
	}

	close(fd);

	return 0;
}
