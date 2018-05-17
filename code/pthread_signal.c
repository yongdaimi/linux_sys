#include <semaphore,h>

#define NUM 5

sem_t blank_number, product_number;
int queue[NUM];

void *producer(void *arg)
{
	int p = 0;
	while(1) {
		sem_wait(&blank_number);		
		
	}
}
