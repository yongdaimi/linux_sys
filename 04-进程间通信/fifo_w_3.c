#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <time.h>
#include <string.h>

int main()
{
	int fd;
	char str[] = "This is a new question\n";	
	int rand_value;
	char buf[100];	

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
		srand((int)time(0)); /*利用time(0)作为随机数种子*/
		while (1) {
			rand_value = 1 + (int)(10.0*rand() / (RAND_MAX+1.0));
			memset(buf, 0, sizeof(buf));
			sprintf(buf, ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>: %d\n", rand_value);
			write(fd, buf, strlen(buf));
			sleep(2);		
		}
		close(fd);
	}
	return 0;
}
