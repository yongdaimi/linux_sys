#include <signal.h>
#include <stdio.h>

int main()
{
	
	sigset_t s;
	sigpending(&s);

	int i;
	for (i = 1; i < 31; i++) {
		printf("signal[%d] -----> %d\n", i, sigismember(&s, i));
	}

	
	return 0;
}
