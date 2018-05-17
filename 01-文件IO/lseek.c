#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

static const char *str = "http://www.ibm.com\n";

int main()
{
	
	int fd;
	off_t offset;
	fd = open("cde.txt", O_RDWR);
	offset = lseek(fd, 0, SEEK_END);
	
	write(fd, str, strlen(str));
	close(fd);	
	printf("cur offset is: %d\n", offset);
	return 0;
}

