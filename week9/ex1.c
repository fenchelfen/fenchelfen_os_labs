#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <err.h>
#include <limits.h>
#include <signal.h>
#include <string.h>
#include <math.h>


typedef struct {
	char counter;
	int pid;
} Entry;

Entry* table;

int table_size;

void black_shift_magic(int signum)
{
	puts("Black magic");
	for (int i = 0; i < table_size; ++i) {
		if (table[i].pid != NULL) {
			table[i].counter /= 2;
		}
	}
}

void insert_new(int page) {
	int min = (int) pow(2, 7);
	int min_pid = -1;
	for (int i = 0; i < table_size; ++i) {
		if (table[i].pid == NULL) {
			table[i].pid = page;
			table[i].counter = (int) pow(2, 7);
			return;
		}
		if (table[i].counter < min) {
			min_pid = i;
		}
	}
	table[min_pid].pid = page;
	table[min_pid].counter = (int) pow(2, 7);
}

int main(int argc, char* argv[])
{
	pid_t clock_generator = fork();
	if (clock_generator == -1) {
		err(EXIT_FAILURE, "fork");
	}

	// Clock generator starts working
	if (clock_generator == 0) {
		const int clock_tick = 0.05;
		for (;;) {
			sleep(clock_tick);
			if (kill(getppid(), SIGINT) == -1) {
				_exit(EXIT_SUCCESS);
			}
		}
	}

	// Updating the table, when SIGINT is caught
	struct sigaction act;
	memset(&act, '\0', sizeof(act));
	act.sa_handler = &black_shift_magic;

	if (sigaction(SIGINT, &act, NULL) != 0) {
		err(EXIT_FAILURE, "sigaction");
	}

	FILE *fp = fopen("in.txt", "r");
	if (argc < 2) {
		errx(EXIT_FAILURE, "Please, give the page table size");
	}
	table_size = strtol(argv[1], NULL, 10);
	table = calloc(table_size, sizeof(Entry));
	if (table == NULL) {
		err(EXIT_FAILURE, "malloc");
	}

	// init. the table
	for (int i = 0; i < table_size; ++i) {
		table[i].counter = 0;
		table[i].pid = NULL;
	}
	
	int page;
	int hits = 0;
	int misses = 0;
	int flag = 0;
	for (int i = 0; fscanf(fp, "%i", &page) != EOF; ++i) {
		printf("%d\n", page);

		// check if page is in the table
		for (int i = 0; i < table_size; ++i) {
			if (table[i].pid == page) {
				if (table[page].counter < (int) pow(2, 7)) {
					table[page].counter += pow(2, 7);
				}
				flag = 1;
				++hits;
			}
		}
		// otherwise, count a miss, replace using the algorithm
		if (flag != 1) {
			insert_new(page);
			++misses;
		}
	}
	fclose(fp);
	return 0;
}
