#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>


int main()
{

	pid_t pid;
	pid = fork();
	if (pid > 0) {
		printf("I am parent, pid is: %d, pgid isi: %d\n", getpid(), getpgrp());	
	} else if (pid == 0) {
		printf("I am child, pid is: %d, pgid is: %d\n", getpid(), getpgrp());
	} else {
		perror("fork");
		exit(1);
	}
	return 0;
}
