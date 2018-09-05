#define ARR_SIZE(a) (sizeof(a) / sizeof(*a))

void swap(int *a, int *b) {
	int t = *a;
	*a = *b;
	*b = t;
}

void bubble_sort(int *arr, int length) {
	for (int j = 0; j < length - 1; ++j) {
		for (int i = 1; i < length; ++i) {
		if (arr[i] - arr[i-1] < 0)
			swap(&arr[i], &arr[i-1]);	
		}
	}
}

void exercise2() {
	int arr[] = { 5, 4, 3, 2, 1 };
	printf("%d\n", ARR_SIZE(arr));
	bubble_sort(arr, ARR_SIZE(arr));
	for (int i = 0; i < ARR_SIZE(arr); ++i)
		printf("%d ", arr[i]);
	putchar('\n');
}

int main() {
	exercise2();
	return 0;
}
