#include <stdio.h> 
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <err.h>
#include <sys/wait.h>


int main()
{
	int pipefd[2];
	if (pipe(pipefd) == -1) {
		err(EXIT_FAILURE, "Pipe failure");	
	}
	
	pid_t child_one = fork();
	if (child_one == -1) {
		err(EXIT_FAILURE, "Fork failure");
	}

	if (child_one == 0) {
		sleep(3);
		char pid_string[16];
		pid_t brother;
		read(pipefd[0], pid_string, strlen(pid_string));;
		brother = strtol(pid_string, NULL, 10);
		kill(brother, SIGTERM);
		fprintf(stdout, "Child one:\tChild two runs no more. Now I will terminate.\n");
		_exit(EXIT_SUCCESS); /* Closes all the fildes. Supposedly, streams are empty so no need to flush */
	} else {
		close(pipefd[0]);
		pid_t child_two = fork();
		if (child_two == -1) {
			err(EXIT_FAILURE, "Fork failure");
		}
		if (child_two == 0) {
			for (;;) { fprintf(stdout,"Child two:\tPlease, clean up! %d\n", getpid()); sleep(1); }
			/* should be killed, be cautious */
		} else {
			char pid_string[16];	
			snprintf(pid_string, 16, "%d", child_two);
			write(pipefd[1], pid_string, strlen(pid_string));
			waitpid(child_one, NULL, WUNTRACED);
			close(pipefd[0]);
			close(pipefd[1]);
			fprintf(stdout, "Parent:\t\tAll is freshly clean!\n");
			exit(EXIT_SUCCESS);
		}
	}
}
