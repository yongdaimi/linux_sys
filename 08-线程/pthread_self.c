#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>



void *printThreadId(void *arg)
{
	pthread_t tid;
	tid = pthread_self();
	printf("current thread id is: %lu\n", tid);
}



int main()
{
	pthread_t tid;
	
	pthread_create(&tid, NULL, printThreadId, NULL);
	printf("I am main thread, id is: %lu\n", tid);
	sleep(2);
	return 0;
}
