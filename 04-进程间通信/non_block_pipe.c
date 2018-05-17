#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>

int main()
{
	
	int fd[2], flags, len;
	pid_t pid;
	char str[] = "This is not impossibile\n";
	char buf[1024];

	if (pipe(fd) < 0) {
		perror("pipe");
	}
	
	// 设置读管道为非阻塞
	flags = fcntl(fd[0], F_GETFL);	
	flags |= O_NONBLOCK;
	fcntl(fd[0], F_SETFL, flags);
	
	pid = fork();
		
	/*父写子读*/
	if (pid > 0) { // parent
		close(fd[0]);
		sleep(6);
		write(fd[1], str, strlen(str));
		wait(NULL);
	} else if (pid == 0) { // child
		close(fd[1]);
tryagain:
		len = read(fd[0], buf, sizeof(buf));
		if (len == -1) {
			if (errno == EAGAIN) { // 读一个非阻塞文件,如果数据没到达,就会出现EAGAIN
				write(STDOUT_FILENO, "try again\n", 10);
				sleep(1);
				goto tryagain;
			} else {
				perror("read");
				exit(1);
			}	
		}
		write(STDOUT_FILENO, buf, len);
	} else {
		perror("fork");
	}
	
	return 0;
}
