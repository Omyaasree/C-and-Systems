// demo.cpp
//
// Show off C++ strings
//
// @author: phaskell


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string>
#include <string.h>


int main() {
	std::string myName = "Paul";
	myName += " ";
	myName.append("Haskell");
	printf("%s\n", myName.c_str());

	int ret = myName.find(" ");
	printf("Found ' ' at %d\n", ret);

	myName.insert(ret+1, "Sparky ");
	printf("%s\n", myName.c_str());

	return 0;
}
