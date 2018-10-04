#include <stdio.h>
#include <stdlib.h>


int main()
{
	char **s = malloc(sizeof(char**));
	char foo[] = "Hell yo world";
	*s = foo;
	printf("s\tis %s\n", *s);
	s[0] = foo;
	printf("s[0]\tis %s\n", *s);
	free(s);
	return (0);
}
