#include <stdio.h>
#include <signal.h>
#include <string.h>
int main()
{

	printf("SIGINT des is: %s\n", strsignal(SIGINT));
	return 0;
}
