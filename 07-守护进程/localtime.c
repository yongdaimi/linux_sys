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

	struct tm *l_time;

	l_time = localtime(&timep);
	
	printf("time is: %d-%d-%d %d:%d:%d\n", (l_time->tm_year+1900), (l_time->tm_mon+1), l_time->tm_mday, l_time->tm_hour, l_time->tm_min, l_time->tm_sec);

	return 0;
}
