#include <stdio.h>
#include <unistd.h>

#define SIZE 6

char buf[SIZE];

int main(){
	setvbuf(stdout, buf, _IOLBF, SIZE);
	printf("H");
	sleep(1);
	printf("a");
	sleep(1);
	printf("n");
	sleep(1);
	printf("n");
	sleep(1);
	printf("a");
	sleep(1);
	printf("h");
	sleep(1);
	printf("\n");
	return 0;
}
