#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

static int counter = 0;

static pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void *run(void *arg) 
{
	int i, j;
	for (i = 0; i < 10; i++) {
		pthread_mutex_lock(&mutex);
		j = counter;
		j+=1;
		counter = j;
		printf("Thread[%ld]: counter is: %d\n", pthread_self(), counter);
		pthread_mutex_unlock(&mutex);
		sleep(2);
	}
}


int main()
{
	pthread_t tidA, tidB;

	pthread_create(&tidA, NULL, run, NULL);
	pthread_create(&tidB, NULL, run, NULL);	
	
	pthread_detach(tidA);
	pthread_detach(tidB);
	
	while (1);
	return 0;
}
