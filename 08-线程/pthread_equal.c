#include <stdio.h>
#include <pthread.h>

void *run(void *arg)
{
	printf("I'm a sub Thread...\n");
}

int main()
{

	pthread_t tid, cid;
	
	pthread_create(&tid, NULL, run , NULL);
	pthread_create(&cid, NULL, run , NULL);

	printf("ret is: %d\n", pthread_equal(tid, cid));

	return 0;
}
