#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

int main()
{

	printf("This is a new question\n");
	printf("This is a dog\n");
	printf("This is a cat\n");
	
	sleep(5);
	raise(9);	

	return 0;
}
