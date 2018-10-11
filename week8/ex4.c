#include <sys/resource.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <err.h>


#define	SIZE 1024*1024*10

int main()
{
	for (int i = 0; i < 10; ++i) {
		int *ptr = malloc(SIZE);	
		if (ptr == NULL) {
			err(EXIT_FAILURE, "malloc");
		}
		memset(ptr, '\0', SIZE);
		struct rusage struct_usage;
		printf("Mem Usage:\t%d\n", getrusage(RUSAGE_SELF, &struct_usage)); /* getrusage is unmaintained for mem */
		perror("");
		sleep(1);
	}
	return 0;
}
