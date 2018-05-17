#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>


int main()
{

	pid_t pid;
	pid = fork();

	if (pid > 0) {
		sleep(5);
		setpgid(pid, pid);
		while (1);
	} else if (pid == 0) {
		while (1) {
			printf("I am child, pid is: %d, gid is: %d\n", getpid(), getpgrp());
			sleep(2);
		}
	} else {
		perror("fork");
		exit(1);
	}
	return 0;
}
