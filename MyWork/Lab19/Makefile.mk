fast: fastmerge.c
	gcc fastmerge.c -o fastmerge -lpthread

helper: helper.c
	gcc helper.c -o helper

testfifo: merge.c
	gcc merge.c -o merge