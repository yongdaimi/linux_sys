#include <string.h>
#include <stdio.h>

int main()
{
	char str[] = "http://www.baidu.com";
	
	char *pstr = str;
	int len, i;
	len = strlen(str);
	printf("current str is: %s\n", str);
	
	/*for (i = 0; i<len; i++) {
		printf("%c", str[i]);
	}*/

	for (i=0; i<len; i++) {
		printf("%c", *(pstr+i));
	}
	printf("\n");
	
	for (i=0; i<len; i++) {
		printf("%c", pstr[i]);
	}
	printf("\n");
	
	for (i=0; i<len; i++) {
		printf("%c", *(str+i));
	}		
	printf("\n");

	return 0;
}


