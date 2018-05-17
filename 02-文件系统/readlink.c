#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
		
	char name[512] = {0};
	int ret = readlink("new_run", name, sizeof(name));
	
	if (ret < 0) {
		perror("readlink");
		exit(1);
	}
	printf("current real file name is: %s\n", name);
	return 0;

}
