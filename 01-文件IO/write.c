#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

static const char *str = "http://www.baidu.com\n";

int main()
{
	int fd;
	fd = open("cde.txt", O_CREAT|O_RDWR|O_APPEND, 0777);
		
	write(fd, str, strlen(str));
	close(fd);
	return 0;
}


