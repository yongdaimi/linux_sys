#include <stdio.h>
#include <pthread.h>

void *run(void *arg)
{
	int i;
	for (i = 0; i < 5; i++) {
		printf("I am a sub Thread.\n");
	}
}


int main()
{

	pthread_t tid;
	pthread_create(&tid, NULL, run, NULL);	
//	pthread_join(tid, NULL);
	pthread_detach(tid);
	while(1);
	return 0;
}
