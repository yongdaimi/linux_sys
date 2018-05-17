#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

void *doSomething(void *arg)
{
	while (1) {
		printf("I am a sub thread\n");
		sleep(2);
	}
}


int main()
{
	pthread_t tid;
	pthread_create(&tid, NULL, doSomething, NULL);

	while (1) {
		printf("I am a main thread\n");
		sleep(2);
	}

	return 0;
}
