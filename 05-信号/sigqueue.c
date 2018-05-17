#include <stdio.h>
#include <stdlib.h>
#include <signal.h>


int main(int argc, char *argv[])
{
	
	char *pid_str = argv[1];
	char *sig_str = argv[2];
	char *int_str = argv[3];

	pid_t pid = atoi(pid_str);
	int signo = atoi(sig_str);	
	int var = atoi(int_str);
	
	printf("send pid is: %d, signo is: %d, value is: %d\n", pid, signo, var);
	union sigval value;
	value.sival_int = var;
	sigqueue(pid, signo, value);	

	return 0;
}
