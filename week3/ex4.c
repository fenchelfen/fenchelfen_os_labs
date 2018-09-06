#include <stdio.h>

void swap(int *a, int *b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

void print_arr(int *array, int lo, int hi)
{
	for (int i = lo; i < hi; ++i)
		printf("%d ", array[i]);
	putchar('\n');

}

/* Partition algorithm from CLRS' book */
int cormen_partition(int *array, int lo, int hi)
{
	int i = lo - 1;
	int pivot = array[hi];

	for (int j = lo; j < hi; ++j) {
		if (array[j] < pivot) {
			++i;
			swap(&array[i], &array[j]);
		}
	}	
	swap(&array[i+1], &array[hi]);
	return (i + 1);
}

/* Ordinary quicksort */
void quick_sort_ord(int *array, int lo, int hi)
{
	if (lo < hi) {
		int q = cormen_partition(array, lo, hi);
		quick_sort_ord(array, lo, q-1);
		quick_sort_ord(array, q+1, hi);
	}
}

/* Tail-recursive quicksort */
void quick_sort(int *array, int lo, int hi)
{
	while (lo < hi) {
		int q = cormen_partition(array, lo, hi);
		quick_sort(array, lo, q-1);
		lo = q + 1;
	}
}

int main()
{
	int array[] = {1, 1, 1, 1, 1};
	//int array[] = {5, 4, 3, 2, 1};
	//int array[] = {1, 2, 3, 4, 5};
	//int array[] = {1};
	//int array[] = {};
	print_arr(array, 0, sizeof(array)/sizeof(*array));
	quick_sort(array, 0, sizeof(array)/sizeof(*array)-1);
	//quick_sort_ord(array, 0, sizeof(array)/sizeof(*array)-1);
	print_arr(array, 0, sizeof(array)/sizeof(*array));
	return 0;
}

