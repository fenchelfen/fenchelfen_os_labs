#include <stdio.h>
#include <stdlib.h>


int main()
{
	int n;
	scanf("%i", &n);
	int *array = malloc(n*sizeof(int));
	for (int i = 0; i < n; ++i) {
		array[i] = i;
	}
	for (int i = 0; i < n; ++i) {
		printf("%d ", array[i]);
	}
	putchar('\n');
	free(array);
	return 0;
}
