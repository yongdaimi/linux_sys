#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

static const char *file_name = "myfifo";
static const char *fifo_id = "FIFO_1";


int main()
{

	int fd;
	char buf[100];
	char revbuf[100];

	if (access(file_name, F_OK) < 0) {
		perror("access");
		if (mkfifo(file_name, 0777) < 0) {
			perror("mkfifo");
			exit(1);	
		}
	} else {
		fd = open(file_name, O_RDWR);
		if (fd < 0) {
			perror("open");
			exit(2);
		}
		while (1) {
			memset(buf, 0, sizeof(buf));
			sprintf(buf, "%s said: %s\n", fifo_id, "I am fifo_1");
			write(fd, buf, strlen(buf));	
			sleep(2);
			int len = read(fd, revbuf, sizeof(revbuf));
			if (len > 0) {
				write(STDOUT_FILENO, revbuf, len);
			}
		}
		close(fd);
	}	
	
	return 0;
}
