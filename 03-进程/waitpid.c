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
			pid_t pid_c = waitpid(0, NULL, WNOHANG);
			printf("go to next...\n");
		}	
	
	} else if (pid == 0) {
		printf("I am child process\n");
		sleep(10);
	} else {
		perror("fork");
	}
	return 0;
}
