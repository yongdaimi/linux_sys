#include <stdio.h>


int main()
{
	
	char *a = "This is";
	char buf[100];
	int i;
	
	sprintf(buf, "%s : %s", a, "She said");
	
	for (i = 0; i < 100; i++) {
		printf("buf[%d] = %d\n", i, buf[i]);
	}	
	
	printf("----------------------\n");
	printf("%s\n", buf);
	return 0;
}
