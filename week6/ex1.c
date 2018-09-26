#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

#define	BUF_SIZE	32

int main()
{
	int pipefd[2];
	if (pipe(pipefd) == -1) {
		perror("pipe");	
		exit(EXIT_FAILURE);
	}
	char string1[BUF_SIZE]; 
	char string2[BUF_SIZE];
	strcpy(string1, "See you Space Cowboy");

	printf("Read-end  fildes:  %d\n", pipefd[0]); /* Probably, 3 */
	printf("Write-end fildes:  %d\n", pipefd[1]); /* Probably, 4 */

	write(pipefd[1], &string1, BUF_SIZE);
	read(pipefd[0], &string2, BUF_SIZE);
	puts(string2);	
	_exit(EXIT_SUCCESS); /* closes all the fildes (doesn't flush streams but I don't mind) */
}
