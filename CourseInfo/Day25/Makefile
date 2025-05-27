# Makefile


## Source file variables
SRCS = numfile.cpp random.cpp readwords.cpp simple.cpp
PRGS = numfile random readwords simple


## Rules
all: $(PRGS)

clean:
	/bin/rm -f $(PRGS)

numfile: numfile.cpp
	g++ -o $@ numfile.cpp

random: random.cpp
	g++ -o $@ random.cpp

readwords: readwords.cpp
	g++ -o $@ readwords.cpp

simple: simple.cpp
	g++ -o $@ simple.cpp
