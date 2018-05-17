#include <stdlib.h>
#include <stdio.h>


int main(int argc, char *argv[])
{

	char *arg = argv[1];
	
	double value = atof(arg);
	
	printf("current value is: %.2f\n", value);
	return 0;
}
