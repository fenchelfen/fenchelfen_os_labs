#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <err.h>

char** split(char *str, int *count);

size_t n;
size_t m;

void free_arr(int **array, int m)
{
	for (int i = 0; i < m; ++i) {
		free(array[i]);
	}
	free(array);
}

void read_nums(int** array, FILE *in)
{
	int buf_size = sizeof(char);
	char *buf = malloc(buf_size);
	char **numbers;
	int c = EOF - 1;

	int i = 0, k;
	for (;;) {
		buf_size = sizeof(char);
		for (k = 0; (c = getc(in)) != '\n'; ++k) {
			if (c == EOF) {
				free(buf);
				return;
			}

			buf = realloc(buf, ++buf_size);
			buf[k] = c;
		}

		// If line is incomplete, return
		if (buf_size < n) {
			free(buf);
			return;
		}

		int count = 0;
		numbers  = split(buf, &count);
		array    = realloc(array, ++m);
		array[i] = realloc(array[i], count);

		if (n < count) {
			n = count;
		}

		for (int j = 0; j < count; ++j) {
			array[i][j] = strtol(numbers[j], NULL, 10);
		}
		++i;
	}
}

int main()
{
	n = 0;
	m = 0;

	int **alloc = malloc(sizeof(int**));
	int **reqst = malloc(sizeof(int**));
	
	*alloc = malloc(sizeof(int*));
	*reqst = malloc(sizeof(int*));

	FILE *in = fopen("input_ok.txt", "r");

	read_nums(alloc, in);
	read_nums(reqst, in);
	
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			printf("%d ", alloc[i][j]);
		}
		putchar('\n');
	}

	putchar('\n');
	// for (int i = 0; i < m; ++i) {
	// 	for (int j = 0; j < n; ++j) {
	// 		printf("%d ", reqst[i][j]);
	// 	}
	// 	putchar('\n');
	// }

	free_arr(alloc, m);
	free_arr(reqst, m);
	fclose(in);
	return 0;
}       
        
char** split(char* str, int* count) {
    char** splits = NULL;
    char* token = strtok(str, " ");

    int spaces = 0;

    while (token) {
        splits = realloc(splits, sizeof(char*) * ++spaces);
        if (!splits) { /* Break to avoid undefined behavior */
     		break; 
        }

        splits[spaces - 1] = token;

        token = strtok(NULL, " "); /* we keep it NULL acc. to the man page */
    }

	*count = spaces;
    return splits;
}
/* split is taken from
   https://www.hackerrank.com/challenges/sock-merchant/problem */
