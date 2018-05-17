#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
	pid_t pid;
	pid = fork();
	
	if (pid == 0) {
		
		printf("I am child process, pid is: %d, gid is: %d, sid is: %d\n", getpid(), getpgrp(), getsid(0));
		setsid();		
		printf("I am child process, pid is: %d, gid is: %d, sid is: %d\n", getpid(), getpgrp(), getsid(0));
		while(1);
	} else if (pid < 0) {
		perror("fork");
		exit(1);
	}
	
	return 0;
}
