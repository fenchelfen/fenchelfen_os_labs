#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>

#define	BUF_SIZE	32

int main()
{
	int pipefd[2];
	if (pipe(pipefd) == -1) {
		perror("Pipe failure");	
		exit(EXIT_FAILURE);
	}
	char string[BUF_SIZE]; 
	char buf;
	strcpy(string, "See you Space Cowboy");

	pid_t cpid = fork();
	if (cpid == -1) {
		perror("Fork failure");
		exit(EXIT_FAILURE);
	}

	if (cpid == 0) {
		close(pipefd[1]);
		while (read(pipefd[0], &buf, 1) > 0) {
			write(STDOUT_FILENO, &buf, 1);
		}
		write(STDOUT_FILENO, "\n", 1);
		close(pipefd[0]);
		_exit(EXIT_SUCCESS); /* _exec is preferred 'cause no exec is used */
	} else {
		close(pipefd[0]);
		write(pipefd[1], string, strlen(string));
		close(pipefd[1]);
		wait(NULL);
		exit(EXIT_SUCCESS);
	}
}

