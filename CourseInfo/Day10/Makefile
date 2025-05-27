# Makefile


# This is the first "target" in the Makefile, so if we just run
# "make", then these "dependencies" get built.
all:  AddrDemo constfun sample simple typed


# If we run "make clean" then this gets run.
# There are no "dependencies".
clean:
	/bin/rm -f AddrDemo constfun sample simple typed


# If we run "make AddrDemo" then this gets built.
AddrDemo: AddrDemo.c
	gcc -o AddrDemo AddrDemo.c

constfun: constfun.c
	gcc -o constfun constfun.c

sample: sample.c
	gcc -o sample sample.c

simple: simple.c
	gcc -o simple simple.c

typed: typed.c
	gcc -o typed typed.c
