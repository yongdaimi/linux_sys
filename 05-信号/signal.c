#include <signal.h>
#include <stdio.h>
#include <stdlib.h>


void printsigset(const sigset_t *set)
{
	int i;
	for (i = 1; i < 32; i++) {
		if (sigismember(set, i) == 1) {
			putchar('1');
			printf("   signal no: %d\n", i);
		} else {
			putchar('0');
			printf("   signal no: %d\n", i);
		}
		puts("");			
	}
}


int main()
{
	sigset_t s, p;
	sigemptyset(&s);	
	sigaddset(&s, SIGINT);
	sigprocmask(SIG_BLOCK, &s, NULL);

	while (1) {
		sigpending(&p);
		printsigset(&p);
		sleep(1);
	}
	return 0;
}
