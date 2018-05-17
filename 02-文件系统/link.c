#include <unistd.h>
#include <stdio.h>

int main()
{
	
	int ret = link("run.exe", "run1");
	if (ret < 0) {
		perror("link");
	}
	return 0;
}
