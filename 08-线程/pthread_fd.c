#include <pthread.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>


void *writeSomething(void *arg)
{
	int *p = (int *)arg;
	int fd = *p;
	char buf[] = "I am Sub thread\n";	
	write(fd, buf, strlen(buf));
}


int main()
{

	int fd;
	pthread_t tid;	

	char buf[] = "I am Main thread\n";
	if ((fd = open("tmp.txt", O_CREAT | O_RDWR, 0777)) < 0) {
		perror("open");
		exit(1);
	}

	write(fd, buf, strlen(buf));
	
	pthread_create(&tid, NULL, writeSomething, (void *)&fd);
	
	sleep(30);
	close(fd);

	return 0;
}
