#include <unistd.h>
#include <stdio.h>


int main()
{
	if (fork() == 0) {
		printf("This is a child process\n");	
	} else {
		printf("This is a parent process\n");
	}
	return 0;
}


