#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>




int main()
{
	
	char buf[4096] = {0};	
	
	int ret = chdir("/home/yongdaimi/ABC");
	if (ret < 0) {
		perror("chdir");
		exit(1);
	}

	char *pathname = getcwd(buf, sizeof(buf));	
	if (pathname != NULL) {
		printf("current working DIR is: %s\n", pathname);
	} else {
		perror("getcwd");
		exit(1);
	}	

	if (access("apple.txt", F_OK) < 0) {
		printf("FILE not found\n");	
	} else {
		printf("FILE has found\n");
	}
	return 0;
}
