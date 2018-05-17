#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>


int main()
{

	int fd;
	off_t offset;
	
	fd = open("cde.txt", O_RDWR);
	
	offset = lseek(fd, 0, SEEK_END);
	printf("cur file size is: %d\n", offset);
	close(fd);
	return 0;
}
