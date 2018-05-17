#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/mman.h>


int main()
{
	int fd, len, *p;
	fd = open("tmp", O_RDWR);
	if (fd < 0) {
		perror("open");
		exit(1);
	}
	len = lseek(fd, 0, SEEK_END);
	p = mmap(NULL, len, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
	if (p == MAP_FAILED) {
		perror("mmap");
		exit(1);
	}
	// If mmap success
	p[0] = 0x30313233;
	close(fd);
	munmap(p, len);
	return 0;
}
