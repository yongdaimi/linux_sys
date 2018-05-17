#include <unistd.h>
#include <stdio.h>


int main()
{
	
	int ret = access("crash", F_OK);
	
	if (ret < 0) {
		perror("access");
	} else {
		printf("file has found\n");
	}
	return 0;
}
