#include <signal.h>
#include <stdio.h>
#include <stdlib.h>


/**
*@brief 打印信号集的内容
*@param s 传递的信号集
*/
void printSigset(sigset_t *s)
{
	int i;
	for (i = 1; i < 31; i++) {
		// 判断信号集中某个信号的标志位是否已置为1
		printf("signo[%d] flag is: %d\n", i, sigismember(s, i));
		puts("");
	}
}


int main()
{
	
	sigset_t s, p;
	sigemptyset(&s);		// 将信号集中所有信号的标志位全置为0
	sigaddset(&s, SIGQUIT);		// 将信号集中SIGQUIT信号的标志位置为1
	
	sigprocmask(SIG_BLOCK, &s, NULL); // 将该信号集添加到阻塞信号集
	
	while (1) {
		sigpending(&p);		// 获取未决信号集内容
		printSigset(&p);	
		sleep(1);
	}
	
	return 0;
}
