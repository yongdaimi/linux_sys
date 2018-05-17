#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{

	pid_t pid;
	
	if ((pid = fork()) < 0) {
		perror("fork");
		exit(1);
	} else if (pid == 0) {
		printf("child process PID is %d\n", getpid());
		printf("child process PGID is %d\n", getpgid(0));
		printf("child process PGID is %d\n", getpgrp());
		printf("child process PGID is %d\n", getpgid(getpid()));
		exit(0);
	}
	
	sleep(3);
	printf("parent process PID is %d\n", getpid());	
	printf("parent process PGID is %d\n", getpgrp());

	return 0;
}
