#include <unistd.h>
#include <stdio.h>


int main()
{
	
	int fd[2];
	
	if (pipe(fd) < 0) {
		perror("pipe");
	}
	
	long value = fpathconf(fd[0], _PC_PIPE_BUF);
	printf("The pipe buf is: %ld\n", value);
	close(fd[0]);
	close(fd[1]);
	return 0;
}
