#include <sys/mman.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>

int main()
{
	int fild = open("ex1.txt", O_RDONLY);
	
	int size_bytes = lseek(fild, 0, SEEK_END);
	char *map = mmap(NULL, size_bytes, PROT_READ | PROT_WRITE, MAP_PRIVATE, fild, 0);
	
	int fild_out = open("ex1.memcpy.txt", O_RDWR | O_CREAT, (mode_t) 0666);
	char *map_out = mmap(NULL, size_bytes, PROT_READ | PROT_WRITE, MAP_SHARED, fild_out, 0);

	ftruncate(fild_out, size_bytes);

	memcpy(map_out, map, size_bytes);
	msync(fild_out, size_bytes, MS_SYNC);
	munmap(map, size_bytes); 
	munmap(map_out, size_bytes); 

	close(fild);
	close(fild_out);
	return 0;
}
