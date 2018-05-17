#include <sys/stat.h>
#include <sys/types.h>
#include <stdio.h>


int main()
{
	
	int ret = mkdir("crash", 0777);
	if (ret < 0) {
		perror("mkdir");
	} else {
		printf("Folder create success\n");
	}
	return 0;
}
