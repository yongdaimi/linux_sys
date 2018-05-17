#include <unistd.h>
#include <stdio.h>

int main(int argc, char *argv[])
{

	char *pid_str = argv[1];
	int pid = atoi(pid_str);
	
	printf("current progress group id is: %d\n", getpgid(pid));
	return 0;
}
