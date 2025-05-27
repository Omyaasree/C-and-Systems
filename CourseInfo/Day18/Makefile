# Makefile

TARGETS = mempool.exe testsem.exe demo.exe

all: $(TARGETS)

clean:
	/bin/rm -f $(TARGETS)

$(TARGETS): %.exe:  %.c
	gcc -g -o $@ $(@:%.exe=%.c) -lpthread
