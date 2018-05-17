#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdio.h>

int main()
{
	
	int fd;
	if ((fd = open("empty.txt", O_RDWR)) < 0) {
		perror("open");
	}

	fchmod(fd, S_IRUSR | S_IWUSR | S_IXUSR | S_IRGRP);
	close(fd);
	return 0;
}
