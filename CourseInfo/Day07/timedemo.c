// filename: timedemo.c
// Only compiles on MacOS or Linux, not Windows?

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

int main() {
	struct timespec start, end;
	clock_gettime(CLOCK_REALTIME, &start);
	printf("%s %s\n", tzname[0], tzname[1]);
	printf("DST? %d\n", daylight);
	clock_gettime(CLOCK_REALTIME, &end);
	printf("duration: %ld\n", end.tv_nsec - start.tv_nsec);
}
