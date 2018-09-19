#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define THREADS_NUM	10

void *print_message(void *th_id)
{
	printf("Greetings from thread %p\n", th_id);
	pthread_exit(NULL);
}

int main()
{
	pthread_t threads[THREADS_NUM];
	int status, i;

	for(int i = 0; i < THREADS_NUM; ++i) {
		printf("Create thread %d\n", i);
		status = pthread_create(&threads[i], NULL, print_message, (void *) i);

		if (status != 0) {
			printf("pthread_create error code: %d\n", status);
			exit(-1);
		}
		pthread_join(threads[i], NULL);
	}	
	exit(0);	
}
