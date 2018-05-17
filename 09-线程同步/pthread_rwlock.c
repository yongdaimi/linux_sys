#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>


#define MAX_THREAD_NUMS 5

static int MAX_REPEAT_COUNT = 5;

static pthread_rwlock_t rwlock;
static int counter = 0;

void *run1(void *arg)
{
	while (MAX_REPEAT_COUNT--) {
		pthread_rwlock_rdlock(&rwlock);
		printf("Thread[%ld]-READ: counter = %d\n", pthread_self(), counter);
		pthread_rwlock_unlock(&rwlock);
		sleep(1);
	}
}

void *run2(void *arg)
{
	while (MAX_REPEAT_COUNT--) {
		pthread_rwlock_rdlock(&rwlock);
		printf("Thread[%ld]-READ: counter = %d\n", pthread_self(), counter);
		pthread_rwlock_unlock(&rwlock);
		sleep(1);
	}
}

void *run3(void *arg)
{
	while (MAX_REPEAT_COUNT--) {
		pthread_rwlock_rdlock(&rwlock);
		printf("Thread[%ld]-READ: counter = %d\n", pthread_self(), counter);
		pthread_rwlock_unlock(&rwlock);
		sleep(1);
	}
}

void *run4(void *arg)
{
	while (MAX_REPEAT_COUNT--) {
		int i, j;
		pthread_rwlock_wrlock(&rwlock);
		j = counter;
		j+= 1;
		counter = j;
		printf("Thread[%ld]-WRITE: counter = %d\n", pthread_self(), counter);
		pthread_rwlock_unlock(&rwlock);
		sleep(1);
	}
}

void *run5(void *arg)
{
	while (MAX_REPEAT_COUNT--) {
		int i, j;
		pthread_rwlock_wrlock(&rwlock);
		j = counter;
		j+= 1;
		counter = j;
		printf("Thread[%ld]-WRITE: counter = %d\n", pthread_self(), counter);
		pthread_rwlock_unlock(&rwlock);
		sleep(1);
	}
}

int main()
{

	int i;
	pthread_t tid[5];
	pthread_rwlock_init(&rwlock, NULL);

	pthread_create(&tid[0], NULL, run1, NULL);
	pthread_create(&tid[1], NULL, run2, NULL);
	pthread_create(&tid[2], NULL, run3, NULL);
	pthread_create(&tid[3], NULL, run4, NULL);
	pthread_create(&tid[4], NULL, run5, NULL);

	for (i = 0; i < MAX_THREAD_NUMS; i++) {
		pthread_detach(tid[i]);
	}

	pthread_rwlock_destroy(&rwlock);
	while (1);
	return 0;
}
