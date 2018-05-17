#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>



int main()
{
	int ret;
	ret = truncate("empty.txt", 0);
	
	if (ret < 0)  {
		perror("truncate");
	}

	return 0;
}
