#include <stdio.h>
#include <unistd.h>

int main()
{
	
	while (1) {
		printf("my pid is: %d, sid is: %d\n", getpid(), getsid(0));
		sleep(2);
	}

	return 0;
}
