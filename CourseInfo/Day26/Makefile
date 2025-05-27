# Makefile


## Source file variables
SRCS = demo.cpp except.cpp except2.cpp
PRGS = demo except except2


## Rules
all: $(PRGS)

clean:
	/bin/rm -f $(PRGS)

$(PRGS): %: %.cpp
	g++ -o $@ $(@:%=%.cpp)
