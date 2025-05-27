// filename showenv.c
//
// Search thru "environment" to get user's name,
// and print it.
// @author: Paul Haskell


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char** argv, char** envp) {
	// Look thru all environment variables to look for
	// user's name.
	while (*envp != 0) {
		// Found a match?
		if (strncmp(*envp, "HOME", 4) == 0) {
			// Found it.  Now find the '=' and skip past it.
			char* p = *envp;
			while (*p != '=' && *p != 0) { p++; }
			if (*p == '=') { p++; }

			// Ok, now print the "value" i.e. the part after the '='.
			printf("Hi %s\n", p);
		}
		envp++;
	}

	return 0;
}
