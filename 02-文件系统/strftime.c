#include <time.h>
#include <stdio.h>



int main()
{
	
	char *format[] = {"%I, %M, %S, %p, %m/%d %a", "%x %X %Y", NULL};
	char buf[30];
	int i;
	time_t clock;
	struct tm *tm;
	time(&clock);
	tm = gmtime(&clock);
	
	for (i = 0; format[i] != NULL; i++) {
		strftime(buf, sizeof(buf), format[i], tm);
		printf("%s=> %s\n", format[i], buf);
	}
	return 0;
}
