#include <stdio.h>
#include <signal.h>


void printsigset(const sigset_t *set)
{	
	int i;
	for (i = 1; i < 32; i++)
		if (sigismember(set, i) == 1) // 测试signum所代表的信号是否已加入参数set的
			// 信号集里，如果信号集里已有该函数则返回1,否则返回0
			putchar('1');
		else 
			putchar('0');
	puts("");
}



int main()
{
	
	sigset_t s,p;
	sigemptyset(&s); // 清空信号集，置0
	sigaddset(&s, SIGINT); // 把信号集的某一个位置置1
	sigprocmask(SIG_BLOCK, &s, NULL); // 修改信号屏蔽字(SIG_BLOCK是添加)
	while(1) {
		sigpending(&p); // 读取当前进程的未决信号集
		printsigset(&p); // 打印信号集
		sleep(1);	
	}

	return 0;
}
