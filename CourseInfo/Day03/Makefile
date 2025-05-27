# Paul's Makefile for demo.c


# Build rules
all: demo.exe demo2.exe

clean:
	rm demo.exe demo.o demo2.o demo2.exe

demo.exe:  demo.o
	gcc -o demo.exe demo.o

demo.o:  demo.c demo.h
	gcc -o demo.o -c demo.c

demo2.exe: demo2.o
	gcc -o demo2.exe demo2.o

demo2.o: demo2.c
	gcc -c -o demo2.o demo2.c
