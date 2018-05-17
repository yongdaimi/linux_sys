#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

static void handle_signal(int signo)
{
	printf("received a signal...signo is: %d\n", signo);
}


int main()
{
	
	struct sigaction act;
	act.sa_handler = handle_signal;
	sigemptyset(&act.sa_mask);
	act.sa_flags = 0;
	sigaction(SIGUSR1, &act, NULL);
	pause();
	// Process Resuming...	
	printf("process resuming.... \n");
	return 0;
}
