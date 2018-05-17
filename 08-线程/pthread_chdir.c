#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

void *get_current_work_dir(void *arg)
{
	char buf[1024] = {0};
	if (getcwd(buf, sizeof(buf)) == NULL) {
		perror("getcwd");
		exit(2);
	}
	printf("current working DIR is: %s\n", buf);
}


int main()
{
	

	if (chdir("./tmp") < 0) {
		perror("chdir");
		exit(1);
	}
	
	pthread_t tid;
	pthread_create(&tid, NULL, get_current_work_dir, NULL);

	sleep(5);
	return 0;
}
