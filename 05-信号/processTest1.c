#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <string.h>

int main()
{
	pid_t pid;
	pid = fork();
	if (pid > 0) {
		while(1) {
			sleep(1);
			int ret = waitpid(0, NULL, WNOHANG);
			if (ret > 0) {
				printf("recycle pid is: %d\n", ret);
			} else {
				char *errStr = strerror(errno);
				char fullMsg[1024] = {0};
				sprintf(fullMsg, "error code is: %d, detail: %s", ret, errStr);		
				printf("%s\n", fullMsg);
			}
		}
	} else if (pid == 0) {
		int n = 10;
		while (n--) {
			sleep(1);
			printf("I am child process[%d]\n", getpid());
		}
	} else {
		perror("fork");
		exit(0);
	}	
	return 0;
}
