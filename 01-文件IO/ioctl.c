#include <sys/ioctl.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>


int main()
{

	struct winsize size;

	if (isatty(STDOUT_FILENO) == 0)
		exit(1);
	if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &size) < 0) {
		perror("ioctl TIOCGWINSZ error");
		exit(1);
	}
	printf("%d rows, %d columns\n", size.ws_row, size.ws_col);
	return 0;
}
