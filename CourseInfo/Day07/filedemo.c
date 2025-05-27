// filename: filedemo.c
// How to read and write from files in C.


// Wow--lots of include files.
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


int main() {
	// Low level lib.
	int fd = open("tempFile.txt", O_WRONLY | O_CREAT);

	char buf[256];
	snprintf(buf, 256, "Wow!  Text in a file!\n");

	write(fd, buf, strlen(buf));
	close(fd);

	// High level lib.
	FILE* fp = fopen("tempFile.txt", "r");
	char buf2[256];
	fread(buf2, 256, 1, fp);
	fclose(fp);
	printf("I read: %s\n", buf2);

	return 0;
}
