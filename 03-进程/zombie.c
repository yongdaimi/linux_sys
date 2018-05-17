#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>


int main()
{

	pid_t pid;
	int n = 10000;
	
	pid = fork();
	if (pid > 0) { /*parent*/
		printf("I am parent process\n");
		while(1);
	} else if (pid == 0) { /*child*/
		printf("I am child process\n");
		sleep(10);
	} else {
		perror("fork");
	}
	return 0;
}
