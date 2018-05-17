#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>



int main()
{	
	
	long ret = pathconf("google.txt", _PC_PATH_MAX);
	if (ret < 0) {
		perror("ret");
		exit(1);
	} else {
		printf("cur value is: %ld\n", ret);
	}
	return 0;
}
