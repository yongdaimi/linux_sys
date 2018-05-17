/* process_mmap_w.c */
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>

#define MAPLEN 0X1000

struct STU {
	int id;
	char name[20];
	char sex;
};

void sys_error(char *str, int exitno)
{
	perror(str);
	exit(exitno);
}


int main(int argc, char *argv[])
{
	
	struct STU *mm;
	int fd, i = 0;
	if(argc < 2) {
		printf("Need filename! \n");
		exit(1);
	}
     	fd = open(argv[1], O_RDWR | O_CREAT, 0777);		
	if (fd < 0)
		sys_error("open", 1);
		
	if (lseek(fd, MAPLEN-1, SEEK_SET) < 0)
		sys_error("lseek", 3);
	
	if (write(fd, "\0", 1) < 0)
		sys_error("write", 4);
	
	mm = mmap(NULL, MAPLEN, PROT_READ|PROT_WRITE, MAP_SHARED, fd, 0);
	if (mm == MAP_FAILED)
		sys_error("mmap", 2);

	close(fd);
	
	while(1) {
		mm->id = i;
		sprintf(mm->name, "zhang-%d", i);
		if (i%2 == 0)
			mm->sex = 'm';
		else
			mm->sex = 'w';
		i++;
		sleep(1);			
	}
	munmap(mm, MAPLEN);
	return 0;
}
