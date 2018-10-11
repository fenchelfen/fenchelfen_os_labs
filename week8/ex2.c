#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <err.h>


#define	SIZE 1024*1024*10

int main()
{
	for (int i = 0; i < 10; ++i) {
		int *ptr = malloc(SIZE);	
		if (ptr == NULL) err(EXIT_FAILURE, "malloc");
		memset(ptr, '\0', SIZE);
		sleep(1);
	}
	return 0;
}
