#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>

int main()
{
	
	char tmp[30];
	char str[1024]; 
	
	int wr_fd;
	wr_fd = open("aaa.txt", O_CREAT|O_WRONLY|O_APPEND, 0777);
	
	int rd_fd;
	rd_fd = open("cde.txt", O_RDONLY);
	
	int total = 0, len;
	while((len = read(rd_fd, tmp, 30))) {
		strncpy(str+total, tmp, len);
		total+=len;
	}
	str[total-1] = '\0';
		
	close(wr_fd);
	close(rd_fd);
	printf("str is: %s\n", str);
	return 0;
}

