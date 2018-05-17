#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[])
{

	char *value = argv[1];
	
	int new = atoi(value);
	printf("current new value is: %d\n", new);	

	return 0;
}
