#include <stdio.h>
#include <unistd.h>

int main()
{
	FILE* fild = fopen("/dev/urandom", "r");

	unsigned char c;
	int k = 0;
	while (k < 20) {
		fread(&c, 1, 1, fild);
		if (c > 0x20 && c < 0x7e) {
			printf("%c", c);
			++k;
		}
	}
	putchar('\n');
	fclose(fild);
	return 0;
}
