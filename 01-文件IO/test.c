#include <string.h>
#include <stdio.h>

static const char *str = "http://www.baidu.com";

int main()
{
	char buf[512] = {0};
	
	strncpy(buf, str, strlen(str));

	 int i = 0;
	//for (i = 0; i<sizeof(buf); i++) {
	//	printf("buf[%d] = %d\n", i, buf[i]);
	//}

	printf("current buf is: %s\n", buf);

	return 0;
}
