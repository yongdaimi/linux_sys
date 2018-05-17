#include <stdio.h>

int main()
{
	char *str1 = "Ac";
	char *str2 = "ba";
	
	int ret = strcmp(str1, str2);
	printf("current ret is: %d\n", ret);
	return 0;
}
