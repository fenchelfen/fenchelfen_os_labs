#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char** split_string(char* str) {
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

	printf("%s\n", splits[0]);  
	printf("%s\n", splits[1]);  
	printf("%s\n", splits[2]);  
	printf("%s\n", splits[3]);  

    return splits;
}
/* split_string source is taken from
   https://www.hackerrank.com/challenges/sock-merchant/problem */

int main()
{
	char something[] = "12 4 7 901 1337";
	char **splits = split_string(something);
	
	return 0;
}
