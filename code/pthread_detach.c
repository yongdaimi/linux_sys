#include <pthread.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

void *thr_fn(void *arg)
{
	int n = 10;
	while(n--) {
		printf("thread count %d\n", n);
		sleep(1);
	}
	return (void *)1;
}


int main()
{	
	
	pthread_t tid;
	void *retval;
	int err;

	pthread_create(&tid, NULL, thr_fn, NULL);
	pthread_detach(tid);
		
	while(1) {
		err = pthread_join(tid, &retval);
		if (err != 0)
			fprintf(stderr, "thread %s\n", strerror(err));
		else 
			fprintf(stderr, "thread exit code %d\n", (int)retval);
		sleep(1);
	}
	return 0;
}
