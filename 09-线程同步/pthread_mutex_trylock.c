#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define MAX_COUNT 10

static int counter = 0;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;


void *run(void *arg)
{
	// pthread_mutex_t *mutex = (pthread_mutex_t *)arg;

	int i, j;
	for (i = 0; i < MAX_COUNT; i++) {

		int ret = pthread_mutex_trylock(&mutex);
		if (ret == 0) {
			sleep(2);
			printf("Thread[%ld], Get lOCK\n", pthread_self());
			pthread_mutex_unlock(&mutex);
		} else if (ret == EBUSY) {
			printf("Thread[%ld], trylock EBUSY\n", pthread_self());
		} else {
			printf("Thread[%ld], trylock error, ret is: %d\n",pthread_self(), ret);
		}
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
