#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <pthread.h>
#include <stdlib.h>

void *get_usr_id(void *arg)
{
	printf("I am Sub thread, uid is: %d\n", getuid());
}


int main()
{
	
	printf("I am Main thread, uid is %d\n", getuid());
	
	pthread_t tid;
	pthread_create(&tid, NULL, get_usr_id, NULL);
	
	sleep(5);
	return 0;
}
