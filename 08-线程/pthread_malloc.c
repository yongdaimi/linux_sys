#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <string.h>

void *print_mem_content(void *arg)
{
	int *p = (int *)arg;
	int i;
	for (i = 0; i < 4; i++) {
		printf("p[%d] = %d\n", i, p[i]);
	}
}


int main()
{
	
	
	int *p = malloc(1024);
	memset(p, 0, 1024);
	
	p[0] = 1;
	p[1] = 2;
	p[2] = 3;
	p[3] = 4;

	pthread_t tid;
	pthread_create(&tid, NULL, print_mem_content, (void *)p);
	
	sleep(5);
	return 0;
}
