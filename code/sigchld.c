#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <stdlib.h>


// 信号监听函数
static void sig_handler(int signo)
{
	int status;
	pid_t pid;
	// 0代表进程组ID与父进程ID相同的所有子进程
	// WNOHANG指定没有子进程结束,立即返回
	while ((pid = waitpid(0, &status, WNOHANG)) > 0){
		if (WIFEXITED(status)) // 判断子进程是否是正常结束
			printf("子进程(%d)正常结束,结果码为:%d\n", pid, WEXITSTATUS(status));
		else if (WIFSIGNALED(status)) // 判断子进程是否是因为信号结束
			printf("子进程(%d)收到信号结束,信号编号为:%d\n", pid, WTERMSIG(status));
	}

}


static void sys_err(const char *errInfo)
{
	perror(errInfo);
	exit(1);
}

int main()
{
	pid_t pid;
	int i;
	
	for (i = 0; i<10; i++) {
		if ((pid = fork()) == 0)
			break;
		else if (pid < 0)
			sys_err("fork");	
	}

	if (pid == 0) {
		int n = 40;
		while(n--) {
			printf("子进程(%d)正在运行\n", getpid());
			sleep(1);
		}
		return i;
	}

	else if (pid > 0) {
		struct sigaction act;
		act.sa_handler = sig_handler;
		sigemptyset(&act.sa_mask); 		
		act.sa_flags = 0;
		sigaction(SIGCHLD, &act, NULL);
		
		while(1) {
			printf("父进程(%d)正在运行\n", getpid());
			sleep(1);
		}
	}	
	
	return 0;
}
