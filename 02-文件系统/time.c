#include <time.h>
#include <stdio.h>

int main()
{
	
	int seconds = time((time_t *)NULL);
	printf("%d\n", seconds);	

	return 0;
}
