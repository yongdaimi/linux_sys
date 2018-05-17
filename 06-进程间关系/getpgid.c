#include <unistd.h>
#include <stdio.h>

int main()
{

	printf("current progress group id is: %d\n", getpgid(0));
	while (1);
	return 0;
}
