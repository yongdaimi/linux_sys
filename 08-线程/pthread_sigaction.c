#include <signal.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

void handle_msg(int signo)
{
	printf("I have received a signal, the signo is: %d\n", signo);
}

void *do_something(void *arg)
{
	while(1) {
		printf("I am sub thread, I can do something\n");
		sleep(2);
	}
}


int main()
{
	
	struct sigaction act;
	act.sa_handler = handle_msg;
	sigemptyset(&act.sa_mask);
	act.sa_flags = 0;
	sigaction(SIGUSR1, &act, NULL);

	pthread_t tid;
	pthread_create(&tid, NULL, do_something, NULL);
	
	while(1) {
		printf("I am main thread, I can do something\n");
		sleep(2);
	}
	return 0;
}
