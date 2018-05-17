#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>


int main()
{
	int fd;
	char str[] = "This is a new question\n";	

	if (access("myfifo", F_OK) < 0) { // File not exists
		int ret = mkfifo("myfifo", 0777);
		if (ret < 0) {
			perror("mkfifo");
			exit(1);
		}
	} else { // file exists
		fd = open("myfifo", O_WRONLY);
		if (fd < 0) {
			perror("open");
			exit(2);
		}
		write(fd, str, strlen(str));
		close(fd);
	}
	return 0;
}
