#include <pthread.h>
#include <stdio.h>

#define NLOOP 5000

/* increment by threads */
int counter;

void *doit(void *vptr)
{
	int i, val;
	for (i=0; i<NLOOP; i++) {
		val = counter;
		printf("%x: %d\n", (unsigned int)pthread_self(), val+1);
		counter = val + 1;
	}
	return NULL;
}


int main()
{
	
	pthread_t tidA, tidB;
	pthread_create(&tidA, NULL, doit, NULL);
	pthread_create(&tidB, NULL, doit, NULL);
	
	
	/* wait for both threads to terminate */
	pthread_join(tidA, NULL);
	pthread_join(tidB, NULL);
	return 0;
}


