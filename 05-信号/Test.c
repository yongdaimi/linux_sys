#include <signal.h>
#include <stdio.h>


void handle_signal(int signo, siginfo_t *siginfo, void *var)
{
	printf("I have received a signal, the signo is: %d\n", signo);
	union sigval aaa = siginfo->si_value;
	printf("The Transmission int is: %d\n", aaa.sival_int);

}


int main()
{
	struct sigaction act;
	act.sa_sigaction = handle_signal;
	sigemptyset(&act.sa_mask);
	act.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &act, NULL);
	while(1);
	return 0;
}
