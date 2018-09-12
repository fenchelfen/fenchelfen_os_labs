#include <stdio.h>
/* #include <sys/types.h> */ // Why doesn't it contain fork?
#include <unistd.h>

int main()
{
	pid_t parent_id = getpid();
       	pid_t child_id = fork();

	printf("Hello from parent\t[PID - %X]\n", parent_id);
	printf("Hello from child\t[PID - %X]\n", child_id);
	putchar('\n');
	return 0;
}
