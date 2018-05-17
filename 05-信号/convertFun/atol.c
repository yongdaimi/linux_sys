#include <stdlib.h>
#include <stdio.h>


int main(int argc, char *argv[])
{
	char *arg = argv[1];

	long value = atol(arg);
	printf("current value is: %ld\n", value);	

	return 0;
}
