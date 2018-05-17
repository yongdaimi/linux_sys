#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{

	time_t now;
	
	if (time(&now) < 0) {
		perror("time");
		exit(1);
	}
	
	char *timep = NULL;
	if ((timep = ctime(&now)) != NULL) {
		printf("cur time is: %s\n", timep);
	}
	
	return 0;
}
