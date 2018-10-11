#include <sys/resource.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <err.h>


#define	SIZE 1024*1024*10

int main()
{
	void *ptrs[10];
	for (int i = 0; i < 10; ++i) {
		ptrs[i] = malloc(SIZE);
		if (ptrs[i] == NULL) {
			err(EXIT_FAILURE, "malloc");
		}
		memset(ptrs[i], '\0', SIZE);
		struct rusage struct_usage;
		getrusage(RUSAGE_SELF, &struct_usage);
		printf("Mem Usage:\t%ld\n", struct_usage.ru_nswap); /* getrusage is unmaintained for ru_nswap (and many others) */
		perror("");
		sleep(1);
	}
	for (int i = 0; i < 10; ++i) {
		free(ptrs[i]);
	}
	return 0;
}
