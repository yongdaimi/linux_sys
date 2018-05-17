#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <string.h>

typedef struct Student {
	char name[512];
	int age;
	int sex;
} stu;


void *run(void *arg)
{
	printf("I am sub Thread, I'm running....\n");
	stu *p = malloc(sizeof(stu));	
	memset(p, 0, sizeof(stu));
	strcpy(p->name, "Jack");
	p->age = 20;
	p->sex = 1;
	pthread_exit(p);
}


int main()
{

	printf("I am main thread\n");

	pthread_t tid;
	pthread_create(&tid, NULL, run, NULL);

	void **retval;
	pthread_join(tid, retval);
	stu *p = (struct Student *)*retval;
	printf("I am in main thread, exe completed\n");
	printf("The person name is: %s, age is: %d, sex is: %d\n", p->name, p->age, p->sex);	
	free(p);
		
	return 0;
}








