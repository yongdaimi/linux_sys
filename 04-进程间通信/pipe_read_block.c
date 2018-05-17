#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	
	int fd[2];
	pid_t pid;
	char str[] = "welcome to Beijing\n";	
	char buf[1024];

	if (pipe(fd) < 0) {
		perror("pipe");
	}
	
	pid = fork();
	/*父写子读*/
	if (pid > 0) { // parent
		close(fd[0]);
		printf("parent process start write data...\n");	
		sleep(5);
		write(fd[1], str, strlen(str));	
		wait(NULL);		
	} else if (pid == 0) { // child
		close(fd[1]);
		printf("child process start read...\n");
		int len = read(fd[0], buf, sizeof(buf));
		write(STDOUT_FILENO, buf, len);	
	} else {
		perror("fork");
	}
	return 0;
}
