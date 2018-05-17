#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
	pid_t pid;
		
	pid = fork();
	if (pid > 0) {
		printf("cur process is parent\n");
		printf("cur pid is: %d\n", getpid());
		printf("cur parent pid is: %d\n", getppid());
		while(1);
	} else if (pid == 0) {
		printf("cur process is child\n");
		printf("cur pid is: %d\n", getpid());
		printf("cur parent pid is: %d\n", getppid());
		while(1);
	} else {
		perror("fork");
	}
	
	return 0;
}
