#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <errno.h>
#include <time.h>
#include <string.h>
#include <dirent.h>


void daemonsize()
{
	pid_t pid;
	if ((pid = fork()) < 0) {
		perror("fork");
		exit(1);	
	} else if (pid != 0) {
		exit(3);
	}

	setsid();

	umask(0);

	if (chdir("/") < 0) {
		perror("chdir");
		exit(2);
	}	

	close(0);
	open("/dev/null", O_RDWR);
	dup2(0, 1);
	dup2(0, 2);
}


int main()
{
	daemonsize();
	/*write current time to /tmp/dameon.log*/
	DIR *dir;	
	if ((dir=opendir("tmp")) == NULL) {
		if (errno == ENOENT) {
			if (mkdir("./tmp", 0777)<0) {
				perror("mkdir");
				exit(4);
			}
		} else {
			perror("opendir");
			exit(6);
		}
	}

	int fd;
	umask(0);
	fd = open("./tmp/daemon.log", O_CREAT | O_RDWR, 0777);
	if (fd < 0) {
		perror("open");
		exit(5);
	}

	char buf[1024] = {0};

	while(1) {
		time_t timep;
		if (time(&timep) < 0) {
			perror("time");
			exit(6);
		}

		struct tm *now;
		now = localtime(&timep);
		memset(buf, 0, sizeof(buf));
		strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M:%S \n", now);
		write(fd, buf, strlen(buf));

		sleep(10);
	}

	return 0;
}
