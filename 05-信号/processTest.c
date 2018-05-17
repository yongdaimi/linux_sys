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
		while(1) {
			sleep(1);
			wait(NULL);
		}
	} else if (pid == 0) {
		int n = 10;
		while (n--) {
			printf("I am child process\n");
		}
	} else {
		perror("fork");
		exit(0);
	}	
	return 0;
}
