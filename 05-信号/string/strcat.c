#include <stdio.h>
#include <string.h>

int main()
{
	
	char buf[1024] = "My Conuntry is: ";
	const char *src = "China";

	char *new = strcat(buf, src);
	printf("%s\n", new);
	return 0;
}

