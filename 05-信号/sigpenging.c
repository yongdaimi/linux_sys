#include <stdio.h>
#include <signal.h>


int main()
{

	
	sigset_t s;
	sigpending(&s);
	
	int i;
	for (i = 1; i < 32; i++) {
		printf("signal[%d] flag is: %d\n", i, sigismember(&s, i));
	}

	return 0;
}
