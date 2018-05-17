#include <unistd.h>
#include <stdio.h>


int main()
{

	execl("./output", "ta", "sf", "jugg", "sk", "od", NULL);
	perror("execl");
	return 0;
}
