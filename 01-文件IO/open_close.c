#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>


int main()
{
	
	int fd;
	fd = open("abc.txt", O_CREAT|O_RDWR, 0777);
	if (fd < 0)
		printf("file create failure");
	printf("current fd is: %d\n", fd);
	close(fd);
	return 0;
}


