// filename:  readwords.cpp
//
// Make a C++ class to return words from a file.


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


// FileReader is not "thread-safe".
// If two different threads call word() at the same time,
// we will get bad results.
class FileReader {
private:
	FILE* fptr;
	char buf[1024];

	void finish() {
		if (fptr != NULL) {
			fclose(fptr);
			fptr = NULL;
		}
	}

public:
	FileReader(const char* fname) : fptr(fopen(fname, "r")) { }

	~FileReader() {
		finish();
	}

	int status() { return fptr != NULL; }

	const char* word() {
		int retval = fscanf(fptr, "%s", (char*) buf);
		if (retval <= 0) {
			finish();
			return NULL;
		}
		return buf;
	}
};


int main() {
	FileReader fr("input.txt");

	while (fr.status()) {
		printf("word> %s\n", fr.word());
	}
}
