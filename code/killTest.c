#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <sys/types.h>
#include <wait.h>

int main()
{
	int status;
	pid_t pid;
	pid = fork();
	if (pid == 0) {
		printf("This is a child processi\n");
		sleep(10);
		return 0;
	} else {
		printf("send a signal to child process(%d)\n", pid);
		sleep(1);
		kill(pid, SIGABRT);
		
	}	

	return 0;
}
