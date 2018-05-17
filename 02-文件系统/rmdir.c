#include <unistd.h>
#include <stdio.h>


int main()
{
	
	int ret = rmdir("crash");
	if (ret < 0) {
		 perror("rmdir");
	} else {
		printf("DIR delete success\n");
	}
	return 0;	
}
