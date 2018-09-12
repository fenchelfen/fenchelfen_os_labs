#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_MAX	32 
#define CMD_START	"$ ) "

char *buffer;

int main(int argc, char **argv)
{
	fputs("Simplistic shell. Welcome\n\n", stdout);

	buffer = malloc(BUFFER_MAX*sizeof(char));
	int i = 0;
	char c;
	fputs(CMD_START, stdout);
	while (fread(&c, sizeof(char), 1, stdin)) {
		buffer[i] = c;
		++i;
		if (c == '\n') {
			fputs(CMD_START, stdout);
			if (i != 1) {
				buffer[i] = '\0';
				system(buffer);
			}
			i = 0;
		}
	}
	fputs("\n\nSee you Space Cowboy\n", stdout);

	return 0;
}
