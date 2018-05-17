#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <stdlib.h>

int main()
{
	int fd;
	char *p;
	fd = open("hello", O_RDWR);
	if (fd < 0) {
		perror("open");
		exit(1);
	}
	
	int offset = lseek(fd, 0, SEEK_END);
	
	p = mmap(NULL, offset, PROT_READ|PROT_WRITE, MAP_SHARED, fd, 0);
	if (p == MAP_FAILED) {
		perror("mmap");
		exit(2);
	}

	close(fd);
	p[0] = 65;
	
	munmap(p, offset);
	return 0;
}
