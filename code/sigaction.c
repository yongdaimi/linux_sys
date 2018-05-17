#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <errno.h>

static void sigHandler(int signum)
{
	static int count = 0;
	if (signum == SIGINT) {
		count++;
		printf("Caught SIGINT (%d)\n", count);
		return;	
	}
	printf("Caught SIGQUIT\n");
	exit(EXIT_SUCCESS);
}


int main()
{

	if (signal(SIGINT, sigHandler) == SIG_ERR)
		perror("sigint error");
	if (signal(SIGQUIT, sigHandler) == SIG_ERR)
		perror("sigquit error");

	for(;;)
		pause();
	return 0;
}
