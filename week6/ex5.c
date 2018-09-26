#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <err.h>
#include <signal.h>

int main()
{
	pid_t child = fork();

	if (child == -1) {
		err(EXIT_FAILURE, "fork");
	}
	if (child == 0) {
		for (;;) {
			puts("Alive am I");
			sleep(1);
		}
	} else {
		sleep(3);
		kill(child, SIGKILL);
		puts("Not any Mo");
		exit(EXIT_SUCCESS);
	}
}

