#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


int main()
{

	int fd;
	fd = open("abc.txt", O_TRUNC|O_RDWR);

	close(fd);
	return 0;
}


