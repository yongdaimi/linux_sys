#include <stdio.h>
#include <unistd.h>


int main()
{
	
	int i = 0;	
	
	alarm(5);
	while(1) {
		printf("current i is: %d\n", i);
		i++;
	}
	return 0;
}
