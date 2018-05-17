#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>


static void handler_child_signal(int signo)
{
	printf("I am PARENT process, I have received child signal\n");
	printf("The signo is: %d\n", signo);
}

static void handler_parent_signal(int signo)
{
	printf("I am CHILD process, I have received parent signal\n");
	printf("The signo is: %d\n", signo);
}


int main()
{

	pid_t pid;

	pid = fork();
	if (pid > 0) { //parent
		int i = 10;
		struct sigaction act;
		act.sa_handler = handler_child_signal;
		sigemptyset(&act.sa_mask);
		sigaddset(&act.sa_mask, SIGQUIT);
		act.sa_flags = 0;
		sigaction(SIGUSR1, &act, NULL);
		
		while(i--) {
			sleep(1);
			kill(pid, SIGUSR2);
		}
	} else if (pid == 0) { // child
		int j = 5;
		struct sigaction act;
		act.sa_handler = handler_parent_signal;		
		sigemptyset(&act.sa_mask);		
		sigaddset(&act.sa_mask, SIGQUIT);
		act.sa_flags = 0;
		sigaction(SIGUSR2, &act, NULL);

		while(j--) {
			sleep(1);
			kill(getppid(), SIGUSR1);
		}
	} else {
		perror("fork");
		exit(1);
	}
	
	return 0;
}
