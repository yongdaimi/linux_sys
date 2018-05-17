#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *run(void *arg)
{
	while(1) {
		printf("I'm sub thread....I'm running....\n");
		sleep(2);
	}
}


int main()
{

	pthread_t tid;
	pthread_create(&tid, NULL, run, NULL);
	pthread_detach(tid);
	
	sleep(20);
	return 0;
}
