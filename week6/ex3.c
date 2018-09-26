#include <stdio.h>
#include <signal.h>
#include <string.h>
#include <stdlib.h>

/**
  * To quit, send SIGQUIT signal. HINT: CTRL-\
  */

void radical_signal_handling(int signum) {
	puts("Be aware, you're now notified.");
}

int main()
{
	struct sigaction act;
	memset(&act, '\0', sizeof(act));
	act.sa_handler = &radical_signal_handling;

	for (;;) {
		if (sigaction(SIGINT, &act, NULL) != 0) {
			perror("Sigaction failure");
			exit(EXIT_FAILURE);
		}
	}
}
