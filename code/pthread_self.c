#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void *printids(void *arg)
{
	const char *str = (const char *)arg;

	pid_t pid;
	pthread_t tid;
	
	pid = getpid();
	tid = pthread_self();
	printf("%s pid %u tid %u (0x%x)\n", str, (unsigned int)pid, (unsigned int)tid, (unsigned int)tid);
	
}




int main()
{	

	pthread_t tid;
	int err;	

	err = pthread_create(&tid, NULL, printids, "new thread: ");
	if (err != 0) {
		fprintf(stderr, "can't create thread: %s\n", strerror(err));
		exit(1);
	}	
	printids("main thread: ");	
	sleep(1);
	return 0;

}
