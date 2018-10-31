#include <sys/stat.h>
#include <sys/mman.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>

const char string[] = "This is a nice day.\n";

int main()
{
	int fild = open("ex1.txt", O_RDWR);
	
	struct stat statbuf;
	stat("ex1.txt", &statbuf);
	printf("ex1.txt is %ld bytes\n", statbuf.st_size);
	int size_bytes = statbuf.st_size;

	char *map = mmap(NULL, size_bytes, PROT_READ | PROT_WRITE, MAP_SHARED, fild, 0);
	ftruncate(fild, strlen(string));
	memcpy(map, string, strlen(string));
	munmap(map, size_bytes);

	close(fild);
	return 0;
}
