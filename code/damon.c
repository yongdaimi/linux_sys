#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


static void damon_process()
{
	pid_t pid;
	if ((pid = fork()) < 0) {
		perror("fork");
		exit(1);
	} else if (pid != 0) {
		exit(1); // 如果是父进程,则退出
	}
	
	setsid();
	
	if (chidr("/") < 0) {
		perror("chdir");
		exit(1);
	}
	
	umask(0);
	close(0);
	open("/dev/null", O_RDWR);
	dup2(0, 1);
	dup2(0, 2);
}






int main()
{

	damon_process();
	while(1);
	return 0;
}




