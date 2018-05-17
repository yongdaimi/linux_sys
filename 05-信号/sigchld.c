#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>
#include <sys/types.h>



void handle_signal(int signo)
{
	printf("I have received a signal, the signo is: %d\n", signo);
	int status;
	pid_t pid;
	while ((pid = waitpid(0, &status, WNOHANG))>0) {
		if (WIFEXITED(status))
			printf("child %d exit %d\n", pid, WEXITSTATUS(status));
		else if (WIFSIGNALED(status))
			printf("child %d cancel signal %d\n", pid, WTERMSIG(status));
	}
}


int main()
{

	pid_t pid;
	pid = fork();
	if (pid > 0) {
		struct sigaction act;
		act.sa_handler = handle_signal;
		sigemptyset(&act.sa_mask);
		act.sa_flags = 0;
		sigaction(SIGCHLD, &act, NULL);
		while (1);
	} else if (pid == 0) {
		int n = 10;
		while (n--) {
			sleep(2);
			printf("I am child process[%d]\n", getpid());
		}
	} else {
		perror("fork");
		exit(1);
	} 	
	return 5;
}
