#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

int main()
{
	int fd;
	char buf[1024];
	
	if (access("myfifo", F_OK) < 0) {
		perror("access");
		exit(1);	
	} else {
		fd = open("myfifo", O_RDONLY);
		if (fd < 0) {
			perror("open");
			exit(2);
		}
		while (1) {
			int len = read(fd, buf, sizeof(buf));
			if (len < 0) {
				perror("read");
				exit(3);
			} else if (len > 0) {
				write(STDOUT_FILENO, buf, len);
			} 
		}
		close(fd);
	}
		
	return 0;
}
