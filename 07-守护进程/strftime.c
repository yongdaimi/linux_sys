#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{

	time_t timep;
	if (time(&timep) < 0) {
		perror("time");
		exit(1);
	}
	struct tm *now;

	now = localtime(&timep);
	
	char buf[512] = {0};
	
	strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M:%S", now);

	printf("%s\n", buf);
		

}
