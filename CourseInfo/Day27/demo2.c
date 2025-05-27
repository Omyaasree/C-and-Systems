// demo2.c


#include <stdio.h>
#include <unistd.h>
#include <signal.h>

int total = 0;
int num;

void gotAlarm(int signum) {
	if (signum == SIGALRM) {
		printf("ALARM WENT OFF\n");
		total = 0;
		alarm(4);
	} else if (signum == SIGUSR1) {
		printf("Numbers mst be positive!\n");
		num = 1;
	}
}

void gotUSR1(int signum) {
	// don't need this anymore
}

int main() {
	alarm(4);
	signal(SIGALRM, gotAlarm);
	signal(SIGUSR1, gotAlarm);

	while (!feof(stdin)) {
		scanf("%d", &num);
		if (num <= 0) {
			raise(SIGUSR1);
		}
		total += num;
		printf("total is %d\n", total);
	}
	return 0;
}
