#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

static int counter;
static pthread_rwlock_t rwlock;

void *th_write(void *arg)
{
	int t, i;
	for (i=0; i<5; i++) {
		pthread_rwlock_wrlock(&rwlock);
		t = counter;
		usleep(100);
		printf("Write Thread(%x) counter=%d, ++counter=%d\n", (int)pthread_self(), t, ++counter);
		pthread_rwlock_unlock(&rwlock);
		usleep(100);
	}

}


void *th_read(void *arg)
{
	while(1) {
		pthread_rwlock_rdlock(&rwlock);
		printf("Read Thread(%x) counter=%d\n", (int)pthread_self(), counter);
		pthread_rwlock_unlock(&rwlock);
		usleep(100);
	}
}


int main()
{
	int i;
	pthread_t tid[8];	

	pthread_rwlock_init(&rwlock, NULL);
	for (i=0; i<3; i++)
		pthread_create(&tid[i], NULL, th_write, NULL);
	for (i=0; i<5; i++)
		pthread_create(&tid[i+3], NULL, th_read, NULL);
	for (i=0; i<8; i++)
		pthread_join(tid[i], NULL);

	pthread_rwlock_destroy(&rwlock);	
	return 0;
}
