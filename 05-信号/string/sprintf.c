#include <stdio.h>


int main()
{
	char buf[1024] = {0};
	
	sprintf(buf,  "My name is: Lucy, my age is:%d", 20);
	printf("%s\n", buf);
	return 0;
}
