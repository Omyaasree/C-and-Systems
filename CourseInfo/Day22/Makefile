# Makefile


## Variables
CSRCS = socketdemo.c clientdemo.c
CPRGS = socketdemo clientdemo
VALOPTS = --tool=memcheck --demangle=yes --leak-check=full -s
COPTS = -g -O0

SGATETARGET = phaskell@stargate.cs.usfca.edu


## Build rules
all: $(CPRGS)

clean:
	/bin/rm -f $(CPRGS)

socketdemo: socketdemo.c
	gcc $(COPTS) -o $@ socketdemo.c

clientdemo: clientdemo.c
	gcc $(COPTS) -o $@ clientdemo.c


## Valgrind rules
valclient: clientdemo
	valgrind $(VALOPTS) clientdemo 10.10.12.81

valserver: socketdemo
	valgrind $(VALOPTS) socketdemo


## "scp" data copying rules
tosgate:
	scp * $(SGATETARGET):/home/phaskell/CS221/Day22

fromsgate:
	scp $(SGATETARGET):/home/phaskell/CS221/Day22/* .
