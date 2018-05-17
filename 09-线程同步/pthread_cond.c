#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>


struct msg {
	struct msg *next;
	int num;
};

struct msg *header;

static pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
static pthread_cond_t has_product = PTHREAD_COND_INITIALIZER;


void *consume(void *arg)
{
	struct msg *mp;
	for(;;) {
		pthread_mutex_lock(&lock);
		while (header == NULL) {
			pthread_cond_wait(&has_product, &lock);
		}
		mp = header;
		header = mp->next;
		pthread_mutex_unlock(&lock);
		printf("Consume--%d\n", mp->num);
		free(mp);
		sleep(rand()%5);
	}
}


void *produce(void *arg)
{
	struct msg *mp;
	while (1) {
		mp = malloc(sizeof(struct msg));
		mp->num = rand()%1000+1;
		printf("Produce--%d\n", mp->num);

		pthread_mutex_lock(&lock);
		mp->next = header;
		header = mp;
		pthread_mutex_unlock(&lock);

		pthread_cond_signal(&has_product);
		sleep(rand()%5);
	}
}



int main()
{
	pthread_t tid[2];
	
	srand(time(NULL));

	pthread_create(&tid[0], NULL, consume, NULL);
	pthread_create(&tid[1], NULL, produce, NULL);
	
	pthread_join(tid[0], NULL);
	pthread_join(tid[1], NULL);

	return 0;
}
