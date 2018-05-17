#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>


int main()
{
	pid_t pid;
	
	if ((pid = fork()) < 0) {
		perror("fork");
		exit(1);
	} else if (pid == 0) {
		printf("\n");
		printf("child process PID is: %d\n", getpid());
		printf("child process PGID is: %d\n", getpgrp());
		printf("child process SID is: %d\n", getsid(0));
		sleep(10);
		setsid(); // 子进程非组长进程,故其成为新会话首进程,且成为组长进程。该进程id即为会话进程
		printf("Changed:\n");
		printf("child process PID is: %d\n", getpid());
		printf("child process PGID is: %d\n", getpgrp());
		printf("child process SID is: %d\n", getsid(0));
		sleep(20);
		exit(0);
	}
	return 0;
}
