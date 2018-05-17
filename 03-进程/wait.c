#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>


int main()
{
	
	pid_t pid;
	pid = fork();

	if (pid > 0) {
		while (1) {
			printf("I am parent process\n");
			printf("wait for child: %d\n", wait(NULL));
			sleep(1);
		}
	} else if (pid ==0) {
		printf("I am child process\n");
		printf("My pid is: %d\n", getpid());
		sleep(10);
	} else {
		perror("fork");
	}
	
	return 0;
}
