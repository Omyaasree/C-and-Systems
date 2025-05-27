// except.cpp
//
// Show off C++ exceptions.
//
// @author: phaskell


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string>


class MyException {
private:
	std::string msg;

public:
	MyException(std::string inp) : msg(inp) { }
	const char* text() { return msg.c_str(); }
};


class DoDivision {
public:
	static double doWeirdMath(double a, double b) {
		if (a > b) {
			return doDivision(a, b);
		}
		return a * b;
	}

	static double doDivision(double a, double b) {
		if (b == 0.0) {
			throw MyException("Dividing by 0");
		}
		return a / b;
	}
};


int main() {
 	try {
		printf("%lf\n", DoDivision::doDivision(5.0, 0.0));
	}
	catch (MyException me) {
		printf("ERROR: %s\n", me.text());
	}
	return 0;
}
