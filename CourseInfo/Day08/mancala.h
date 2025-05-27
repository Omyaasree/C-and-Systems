#ifndef MANCALA
#define MANCALA

struct Mancala {
	int aPlayer[6];
	int bPlayer[6];
	int aScoring;
	int bScoring;
};

void init(struct Mancala*);

void printScore(struct Mancala*);

#endif
