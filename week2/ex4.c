#include <stdio.h>

void swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

int main()
{
	printf("Hey-ho, give me two integers!\n");
	int a, b;
	scanf("%d %d", &a, &b);
	swap(&a, &b);
	printf("%d %d\n", a, b);
	return 0;
}
