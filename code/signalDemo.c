#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void recv_sig(int signum)
{
	printf("I have received a sig\n");

	if (signum == SIGINT) {
		printf("The signal is SIGINT\n");
	} else if (signum == SIGQUIT){
		printf("The signal is SIGQUIT\n");
	}
}


int main()
{
	
	struct sigaction act;
	
	act.sa_handler = recv_sig;
	sigemptyset(&act.sa_mask);
	act.sa_flags = 0;

	sigaction(SIGINT, &act, NULL);	
	sigaction(SIGQUIT, &act, NULL);	

	static int m;
	
	while(1) {
		printf("m = %d\n", m);
		sleep(1);
		m++;
	}
	return 0;
}



