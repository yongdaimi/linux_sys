#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

void daemonize(void)
{

	pid_t pid;
	
	/*成为一个新会话的首进程， 失去控制终端*/
	if ((pid = fork()) < 0) {
		perror("fork");
		exit(1);
	} else if (pid != 0)
		exit(0);

	setsid();
	
	/*修改当前工作目录至/目录下*/
	if (chdir("/") < 0) {
		perror("chdir");
		exit(1);
	}

	/*设置umask为0*/
	umask(0);

	/*重定向0,1,2文件描述符到/dev/null，因为已经失去控制终端,再操作0,1,2没有意义*/
	close(0);
	open("/dev/null", O_RDWR);
	dup2(0, 1);
	dup2(0, 2);
	
}

int main()
{
		
	daemonize();
	while (1) {
		printf("I am a damon process...\n");
		sleep(2);
	}
	return 0;
}

