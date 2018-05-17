#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <sys/stat.h>
#include <stdlib.h>

int main()
{
	DIR *dir = opendir("tmp");
	
	if (dir == NULL) {
		if (errno == ENOENT) {
			printf("目录不存在\n");
			if (mkdir("tmp", 0777) < 0) {
				perror("mkdir");
				exit(1);
			}
		}
	}
	
	return 0;
}
