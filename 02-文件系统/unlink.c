#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>


static const char *str = "www.baidu.com";
static const char *filename = "201321321313131313131313131313131.tmp";


int main()
{
	
	int fd;
	if ((fd = open(filename, O_CREAT|O_RDWR, 0777)) < 0) {
		perror("open");
		exit(1);
	}
	
	int ret = write(fd, str, strlen(str));
	if (ret < 0) {
		perror("write");
		exit(1);
	}
	
	sleep(30);
	close(fd);
	unlink(filename);
	return 0;
}
