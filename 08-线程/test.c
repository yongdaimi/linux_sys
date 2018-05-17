#include <stdio.h>
#include <pthread.h>

int main()
{
	
	printf("sizeof(void *) len is: %lu\n", sizeof(long *));
	printf("sizeof(int) len is: %lu\n", sizeof(int));	
	printf("sizeof(pthread_t) len is: %lu\n", sizeof(unsigned long));

	return 0;
}
