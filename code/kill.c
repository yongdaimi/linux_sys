#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <wait.h>


int main()
{
	pid_t pid;
	int status;
	
	if (!(pid = fork())) {
		printf("I am a child process!");
		sleep(10);
		return;
	} else {	
		printf("Send a signal to child process(%d)\n", pid);
		sleep(1);
		kill(pid, SIGABRT);
		wait(&status);
		if (WIFSIGNALED(status))
			printf("child process receive a signal %d\n", WTERMSIG(status));
	}			

	return 0;
}
