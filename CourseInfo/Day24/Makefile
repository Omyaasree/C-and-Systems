# Makefile


##
## Variables
##
CSRCS = BinTree.c BinTreeSoln.c NonBinTree.c NonBinTreeSoln.c showenv.c
CPRGS = BinTree BinTreeSoln NonBinTree NonBinTreeSoln showenv
COPTS = -g -O0
VALOPTS = --tool=memcheck --demangle=yes --leak-check=full --track-origins=yes -s

SGATEUSER = phaskell@stargate.cs.usfca.edu
SGATEDIR = /home/phaskell/CS221/Day24
SGATETARGET = $(SGATEUSER):$(SGATEDIR)


##
## Build rules
##
all: $(CPRGS)

clean:
	/bin/rm -f $(CPRGS)


BinTreeSoln: BinTreeSoln.c
	gcc $(COPTS) -o $@ BinTreeSoln.c

NonBinTreeSoln: NonBinTreeSoln.c
	gcc $(COPTS) -o $@ NonBinTreeSoln.c

showenv: showenv.c
	gcc $(COPTS) -o $@ showenv.c


##
## Valgrind rules
##
valbin: BinTreeSoln
	valgrind $(VALOPTS) BinTreeSoln

valnonbin: NonBinTreeSoln
	valgrind $(VALOPTS) NonBinTreeSoln


##
## Stargate push/pull rules
##
tosgate:
	scp $(CSRCS) Makefile $(SGATETARGET)

fromsgate:
	scp $(SGATETARGET)/* .
