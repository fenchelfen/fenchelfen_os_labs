#include <stdio.h>
#include <signal.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

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

	if (sigaction(SIGINT, &act, NULL) != 0) {
		perror("Sigaction failure");
		exit(EXIT_FAILURE);
	}

	for (;;) { sleep(3); }
}
