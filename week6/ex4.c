#include <stdio.h>
#include <signal.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

/**
  *  The signals SIGKILL and SIGSTOP cannot be caught, blocked, or ignored. SIGNAL(7)
  */

void sigkill_handler()
{
}

void sigstop_handler(int signum)
{
}

void sigusr1_handler()
{
	puts("Hackety hack! SIGUSR1");
}

int main()
{
	struct sigaction sigkill_act;
	sigkill_act.sa_handler = &sigkill_handler;
	struct sigaction sigstop_act;
	sigstop_act.sa_handler = &sigstop_handler;
	struct sigaction sigusr1_act;
	sigusr1_act.sa_handler = &sigusr1_handler;

	if (sigaction(SIGKILL, &sigstop_act, NULL) < 0) {
		perror("\nFailed to change SIGKILL");
		//exit(EXIT_FAILURE);
	}
	if (sigaction(SIGSTOP, &sigstop_act, NULL) < 0) {
		perror("\nFailed to change SIGSTOP");
		//exit(EXIT_FAILURE);
	}
	if (sigaction(SIGUSR1, &sigstop_act, NULL) < 0) {
		perror("Failed to change SIGUSR1");
		exit(EXIT_FAILURE);
	}

	for (;;) { sleep(3); }
}
