// Omyaasree
// sigfun.c
// this code prints out relavant exception errors handled working through signals

#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <time.h>

int total = 0; // total to keep track of the time
char name[256];

void alarm1(int SIGNUM) {
    if (SIGNUM == SIGALRM) {
        printf("the alarm is going off\n");
        total += 5;
        alarm(5);
        printf("the programs total running time till now is %ds\n", total);
    } else if (SIGNUM == SIGINT) {// Handles CTRL+C (interrupt signal)
        printf("Ouch!\n");

    } else if (SIGNUM == SIGTSTP) {// Handles CTRL+Z (stop signal)
        printf("You can't make me stop!\n");
    }
}


int main() {
    alarm(5);
    signal(SIGALRM, alarm1);// handle alarm signal
    signal(SIGINT, alarm1);
    signal(SIGTSTP, alarm1);

    while (!feof(stdin)) {// Loop until the end of input

        clock_t start = clock(); // not required
        scanf("%s", name);
        clock_t end = clock(); // not required
        printf("Hi %s\n", name);// print user input
    }
    return 0; // exit the code
}
