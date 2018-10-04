#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <err.h>


void *radical_realloc(void *ptr, size_t orig_size, size_t size)
{
	if (ptr == NULL) {
		ptr = malloc(size*sizeof(void));
		if (ptr == NULL) {
			err(EXIT_FAILURE, "malloc in realloc");
		}
		return ptr;
	}
	if (size == 0) {
		free(ptr);
		return NULL;
	}
	if (size == orig_size) {
		return ptr;
	}
	else {
		void *new_ptr = malloc(size);
		if (new_ptr == NULL) {
			err(EXIT_FAILURE, "malloc in realloc");
		}
		if (orig_size < size) {
			puts("Flag A");
			memcpy(new_ptr, ptr, orig_size);
		} else {
			memcpy(new_ptr, ptr, size);
		}
		free(ptr);
		return new_ptr;
	}
}

int main()
{
	char *string = malloc(64);
	strcpy(string, "something_");
	puts(string);
	printf("%lu\n", malloc_usable_size(string));
	string = radical_realloc(string, strlen(string), 8);
	puts(string);
	printf("%lu\n", malloc_usable_size(string));
	free(string);
	return 0;
}
