#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int main()
{
	
	int fd;
	if ((fd = open("hh.txt", O_RDWR | O_CREAT | O_EXCL, 0664)) == -1) {
		perror("open error");
		exit(1);
	}	
	
	int var;
	if ((var = fcntl(fd, F_GETFL, 0)) < 0) {
		perror("fcntl error");
		close(fd);
		exit(1);
	}
	
	switch(var & O_ACCMODE) {
		case O_RDONLY:
			printf("Read only ...\n");
		break;
		case O_WRONLY:
			printf("Write only ...\n");
		break;
		case O_RDWR:
			printf("Read And Write ...\n");
		break;
		default:
			printf("Do't know...\n");
		break;
	}

	if (var & O_APPEND) {
		printf("And Append...\n");
	}
	if (var & O_NONBLOCK) {
		printf("And Blocking...\n");
	}
	if (close(fd) == -1) {
		perror("close error");
	}

	return 0;
}
