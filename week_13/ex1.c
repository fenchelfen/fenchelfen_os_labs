#include <stdlib.h>
#include <string.h>
#include <stdio.h>

size_t n;
size_t m;

char** split(char* str, int* count);

int main()
{
	// int alloc[n][m];
	// int reqst[n][m];

	FILE *in = fopen("input_ok.txt", "r");

	char *buf = malloc(32);
	char **numbers;
	int c;
	while (c != EOF) {
		int i;
		int count = 0;
		for (i = 0; (c = getc(in)) != '\n'; ++i) {
			if (c == EOF)
				break;

			buf[i] = c;
		}
		numbers = split(buf, &count);
		printf("Count %d \n", count);
		for (int j = 0; j < count; ++j) {
			puts(numbers[j]);
		}
	}

	// for (int i = 0; i < n; ++i) {
	// 	for (int j = 0; j < m; --j) {
	// 		printf("%d", alloc[i][j]);
	// 	}
	// }

	fclose(in);
	free(buf);
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
/* split_string source is taken from
   https://www.hackerrank.com/challenges/sock-merchant/problem */
