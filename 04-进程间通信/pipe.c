#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <string.h>
#include <stdlib.h>

int main()
{

	int fd[2];
	pid_t pid;
	char str[] = "This is a new question\n";
	char buf[1024];	

	// 父写子读
	if (pipe(fd) < 0) {
		perror("pipe");
	}
		
	pid = fork();
	if (pid > 0) { // parent
		//  关闭父读
		close(fd[0]);
		write(fd[1], str, strlen(str));
		sleep(3);
		// 回收子进程
		wait(NULL);
	} else if (pid == 0) { // child
		// 关闭子写
		close(fd[1]);
		int len = read(fd[0], buf, sizeof(buf));		
		write(STDOUT_FILENO, buf, len);
	} else {
		perror("fork");
	}
	return 0;
}
