#include <stdlib.h>	
#include <pthread.h> 
#include <stdio.h>

void *run(void *arg)
{
	int i = 10;
	while(i--) {
		printf("i is: %d\n", i);
		sleep(2);
	}
	pthread_exit(NULL);
}

int main()
{

	pthread_t tid;
	pthread_create(&tid, NULL, run, NULL);	

	while(1);
	return 0;
}
