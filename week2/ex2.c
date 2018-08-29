#include <stdio.h>
#include <string.h>

#define SIZE 64 

int main()
{
	int i = 0; 
	char string[SIZE];
	fgets(string, SIZE, stdin);
	fputs(string, stdin);
	int len = strlen(string);
	if (*(string+len-1) == '\n') --len;
	while(putchar(*(string+(--len)))); 
	putchar('\n');
	return 0;
}
