#include <stdio.h>
#include <stdlib.h>

void asterix_triangle(int i, int k)
{
	for (int j = 0; j < i+1; ++j)
		putchar(' ');
	for (int j = 0; j < k*2+1; ++j)
		putchar('*');
	putchar('\n');
	if (i == 0) return;
	asterix_triangle(i-1, k+1);
}

int main(int argc, char *argv[])
{
	asterix_triangle(atoi(argv[1]), 0);
	return 0;
}
