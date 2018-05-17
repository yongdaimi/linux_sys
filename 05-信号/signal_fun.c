#include <stdio.h>
#include <signal.h>


static void handle_signal(int signo)
{
	printf("I have received a signal.\n");
	printf("The signal no is: %d\n", signo);
}


int main()
{
	signal(SIGINT, handle_signal);
	while(1);
	
	return 0;
}
