#include <stdlib.h>
#include <stdio.h>
#include <err.h>

# define NUM_FILES 10

int main(int argc, char **argv)
{
	FILE *outs[NUM_FILES];
	if (argc == 1) {
		errx(EXIT_FAILURE, "Give a filename, please");
	}

	outs[0] = stdin;
	for (int i = 1; i < argc; ++i) {
		outs[i] = fopen(argv[i], "w+");
		if (outs[i] == NULL) {
			errx(EXIT_FAILURE, "fopen %s", argv[i]);
		}
	}

	int c;
	while ((c = getchar()) != EOF) {
		for (int i = 0; i < argc; ++i) {
			fprintf(outs[i], "%c", c);
		}
	}

	for (int i = 1; i < argc; ++i) {
		fclose(outs[i]);
	}
	return 0;
}
