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
		printf("child process PID is: %d\n", getpid());
		printf("child process PGID is: %d\n", getpgrp());
		sleep(5);
		printf("child process PGID is: %d\n", getpgrp());
		exit(0);
	}
	
	sleep(1);
	// 改变子进程的组ID为子进程本身
	setpgid(pid, pid);	
	sleep(5);
	
	printf("parent process PID is:  %d\n", getpid());
	printf("parent process PPID is: %d\n", getppid());
	printf("parent process PGID is: %d\n", getpgrp());
	setpgid(getpid(), getppid()); // 改变父进程的组ID为父进程的父进程
	printf("parent process PGID has changed to: %d\n", getpgrp());
	return 0;
}
