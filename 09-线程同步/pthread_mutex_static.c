#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

#define MAX_COUNT 10

static int counter = 0;
static pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;


void *run(void *arg)
{
	int i, j;
	for (i = 0; i < MAX_COUNT; i++) {
		pthread_mutex_lock(&mutex);
		j = counter;
		j += 1;
		counter = j;
			printf("Thread[%ld] modify the counter, counter is: %d\n", pthread_self(), counter);	
		pthread_mutex_unlock(&mutex);
		sleep(2);
	}

}


int main()
{

	pthread_t tid1, tid2;

	pthread_create(&tid1, NULL, run, NULL);
	pthread_create(&tid2, NULL, run, NULL);

	pthread_detach(tid1);
	pthread_detach(tid2);

	while(1);
	return 0;
}
