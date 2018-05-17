#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

#define MAX_COUNT 10

static int counter = 0;


void *run(void *arg)
{
	pthread_mutex_t *mutex = (pthread_mutex_t *)arg;
	
	int i, j;
	for (i = 0; i < MAX_COUNT; i++) {
		pthread_mutex_lock(mutex);
		j = counter;
		j += 1;
		counter = j;
			printf("Thread[%ld] modify the counter, counter is: %d\n", pthread_self(), counter);	
		pthread_mutex_unlock(mutex);
		sleep(2);
	}

}


int main()
{

	pthread_t tid1, tid2;

	pthread_mutex_t mutex;
	pthread_mutex_init(&mutex, NULL);
	
	pthread_create(&tid1, NULL, run, &mutex);
	pthread_create(&tid2, NULL, run, &mutex);

	pthread_detach(tid1);
	pthread_detach(tid2);

	pthread_mutex_destroy(&mutex);
	while(1);
	return 0;
}
