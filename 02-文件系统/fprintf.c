#include <stdio.h>


static const char *str = "new dialog\n";


int main()
{
	
	int i = 150;
	int j = -100;
	double k = 3.14159;

//	fprintf(stdout, "%d %f %x\n", j, k, i);
//	fprintf(stdout, "%2d %*d\n", i, 2, i);
	
	fprintf(stdout, "%s", str);
	
	return 0;
}
