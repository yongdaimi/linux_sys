#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <fcntl.h>

#define MAPLEN 0x1000

struct STU {
	int id;
	char name[20];
	char sex;
};


int main(int argc, char *argv[])
{

	struct STU *mm;
	int fd;

	if (argc < 2) {
		printf("./a.out filename\n");
		exit(1);
	}
	
	fd = open(argv[1], O_RDWR);
	if (fd < 0) {
		perror("open");
		exit(2);
	}	
	
	mm = mmap(NULL, MAPLEN, PROT_READ|PROT_WRITE, MAP_SHARED, fd, 0);
	if (mm == MAP_FAILED) {
		perror("mmap");
		exit(3);
	}

	close(fd);
	unlink(argv[1]);
	while (1) {
		printf("%d\n", mm->id);
		printf("%s\n", mm->name);
		printf("%c\n", mm->sex);
		sleep(1);
	}
	munmap(mm, MAPLEN);
	return 0;
}
