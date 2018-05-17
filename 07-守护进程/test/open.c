#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>



int main()
{
	int fd;
	if ((fd = open("./tmp/damon.log", O_CREAT | O_RDWR, 0777)) < 0) {
		perror("open");
		exit(1);
	}


	return 0;
}
