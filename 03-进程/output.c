#include <stdio.h>


int main(int argc, char *argv[])
{
	
	int i;
	for (i = 0; i < argc; i++) {
		printf("The arg[%d] is: %s\n", i, argv[i]);
	}

}
