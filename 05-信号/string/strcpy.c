#include <string.h>
#include <stdio.h>

int main()
{
	char dest[1024] = {0};
	const char *src = "Today is new monday";
	char *str = strncpy(dest, src, 8);
	printf("%s\n", str);
	return 0;
}
