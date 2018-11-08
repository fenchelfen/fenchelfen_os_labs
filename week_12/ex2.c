#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <err.h>

#define NUM_FILES 10
#define MAXBUFLEN 64

int main(int argc, char **argv)
{
	int outs[NUM_FILES];

	if (argc == 1) {
		errx(EXIT_FAILURE, "Give a filename, please");
	}

	outs[0] = STDOUT_FILENO;
	umask(0);
	for (int i = 1; i < argc; ++i) {
		outs[i] = open(argv[i], O_APPEND | O_CREAT | O_WRONLY, 0666);
		if (outs[i] < 0) {
			err(EXIT_FAILURE, "open %s", argv[i]);
		}
	}

	int c;
	size_t size = 0;
	char *buf = malloc(MAXBUFLEN);
	while ((size = read(STDIN_FILENO, buf, MAXBUFLEN)) != 0) {
		if (size < 0) {
			err(EXIT_FAILURE, "read");
		}
		for (int i = 0; i < argc; ++i) {
			if ((write(outs[i], buf, size)) < 0) {
				err(EXIT_FAILURE, "write");
			}
		}
	}

	for (int i = 1; i < argc; ++i) {
		close(outs[i]);
	}
	return 0;
}
