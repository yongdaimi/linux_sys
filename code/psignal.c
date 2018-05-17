#include <signal.h>

int main()
{
	psignal(SIGINT, "xp.chen");
	return 0;
}
