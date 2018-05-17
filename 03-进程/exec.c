#include <unistd.h>
#include <stdlib.h>

int main()
{
	
	// execl("/bin/ls", "ls", "-l", NULL);
	char *const ps_argv[] = {"ps", "aux", NULL};
	//execvp("ps", ps_argv);
	execlp("ps", "ps", "-o", "pid,ppid,pgrp,session,tpgid,comm", NULL);
	perror("exec ps");
	exit(1);
	return 0;
}
