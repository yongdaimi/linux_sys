#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>

#define MAPLEN 0x1000


struct STU {
	int id;
	char name[20];
	char sex;
};




int main(int argc, char *argv[])
{
	struct STU *mm;
	int fd, i = 0;

	if (argc < 2) {
		printf("./a.out filename\n");
		exit(1);
	}
	fd = open(argv[1], O_CREAT|O_RDWR, 0777);	
	if (fd < 0) {
		perror("open");
		exit(2);
	}

	if (lseek(fd, MAPLEN-1, SEEK_SET) < 0) {
		perror("lseek");
		exit(3);
	}

	if (write(fd, "\0", 1) < 0) {
		perror("write");
		exit(4);
	}

	mm = mmap(NULL, MAPLEN, PROT_READ|PROT_WRITE, MAP_SHARED, fd, 0);
	if (mm == MAP_FAILED) {
		perror("mmap");
		exit(5);
	}
	close(fd);

	while (1) {
		mm->id = i;
		sprintf(mm->name, "zhang-%d", i);
		if (i % 2 == 0) {
			mm->sex = 'm';
		} else {
			mm->sex = 'w';
		}
		i++;
		sleep(1);
	}

	munmap(mm, MAPLEN);
	return 0;
}
