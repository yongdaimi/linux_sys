#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

static int counter = 0;
static pthread_rwlock_t rwlock = PTHREAD_RWLOCK_INITIALIZER;


void *read(void *arg)
{
	int i;
	for (i = 0; i < 5; i++) {
		pthread_rwlock_rdlock(&rwlock);
		printf("Thread[%ld] read: counter is: %d\n", pthread_self(), counter);
		pthread_rwlock_unlock(&rwlock);
		sleep(2);
	}
}


void *write(void *arg)
{
	int i, j;
	for (i = 0; i < 5; i++) {
		pthread_rwlock_wrlock(&rwlock);
		j = counter;
		j+=1;
		counter = j;
		printf("Thread[%ld] write: counter is: %d\n", pthread_self(), counter);
		pthread_rwlock_unlock(&rwlock);
		sleep(2);
	}
}


int main()
{

	pthread_t tid[5];

	pthread_create(&tid[0], NULL, read, NULL);	
	pthread_create(&tid[1], NULL, read, NULL);	
	pthread_create(&tid[2], NULL, read, NULL);	
	pthread_create(&tid[3], NULL, write, NULL);	
	pthread_create(&tid[4], NULL, write, NULL);	

	int i;
	for (i = 0; i < 5; i++) {
		pthread_detach(tid[i]);
	}

	while(1);		
	return 0;
}
