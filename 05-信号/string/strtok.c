#include <string.h>
#include <stdio.h>


int main()
{
	
	/*char buf[] = "hello@boy@this@is@heima";

	char *tmp = strtok(buf, "@");
	while(tmp) {
		printf("%s ", tmp);
		tmp = strtok(NULL, "@");
	}
	printf("\n");
	*/
	
	char buf[] = "hello@boy@this@is@heima";
	int i = 0, j;
	char *last[20] = {NULL};
	char *tmp = strtok(buf, "@");
	while (tmp) {
		last[i] = tmp;
		tmp = strtok(NULL, "@");
		i++;
	}	
	
	for (c)
		

	return 0;
}
