#include <stdio.h>
#include <signal.h>
#include <stdlib.h>


void handle_signal(int signo)
{
	printf("I have received the signal\n");
	sleep(5); // 模拟正在处理...
	printf("The signo is: %d\n", signo);
}


int main()
{
	struct sigaction act;
	act.sa_handler = handle_signal;
	sigemptyset(&act.sa_mask);
	sigaddset(&act.sa_mask, SIGQUIT); //设置临时信号屏蔽字
	act.sa_flags = 0;
	
	if (sigaction(SIGINT, &act, NULL) < 0) {
		perror("sigaction");
		exit(1);
	}
	
	while (1) {
		printf("****************************\n");
		sleep(1);
	}
	return 0;
}
