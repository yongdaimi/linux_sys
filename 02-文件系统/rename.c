#include <stdio.h>



int main()
{
	
	
	int ret = rename("new.txt", "new1.txt");
	if (ret < 0) {
		perror("rename");
	}
	return 0;
}
