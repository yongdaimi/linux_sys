#include <unistd.h>


int main()
{
	

	int ret = symlink("run.exe", "new_run");
	if (ret < 0) {
		perror("symlink");
	}
	return 0;
}
