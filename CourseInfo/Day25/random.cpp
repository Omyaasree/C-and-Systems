// filename:  random.cpp
//


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <math.h>



class Uniform {
private:
	static int initialized;
	double min, max;
public:
	Uniform(double mmin, double mmax) {
		min = mmin;
		max = mmax;
		if (!initialized) {
			srand(time(0));
			initialized++;
		}
	}
	double next() {
		return min + (max-min)*rand()/RAND_MAX;
	}
};

// This is how we initialize a static class variable.
int Uniform::initialized = 0;


// Inheritance from class Uniform
class Exponential : public Uniform {
private:
	double negMean;

public:
	Exponential(double mean) : Uniform(0.0, 1.0) {
		negMean = -1.0*mean;
	}
	double next() {
		return negMean*log(Uniform::next());
	}
};


int main() {
	Exponential myExp(5.0);

	double total = 0.0;
	for (int c = 0; c < 20; c++) {
		const double thisOne = myExp.next();
		total += thisOne;
		printf("%lf\n", thisOne);
	}
	printf("Average is %lf\n", total/20.0);
}
