#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>


static int i = 5;

void *print_value(void *arg)
{
	printf("current i is: %d\n", i);
}


int main()
{

	printf("current i is: %d\n", i);
	
	pthread_t tid;
	pthread_create(&tid, NULL, print_value, NULL);
		
	sleep(5);
	return 0;
}
