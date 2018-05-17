#include <pthread.h>
#include <stdio.h>
#include <unistd.h>


void *thr_fn1(void *arg)
{
	printf("thread 1 returning\n");
	return (void*)1;
}


void *thr_fn2(void *arg)
{
	printf("thread 2 exiting\n");
	pthread_exit((void*)2);
}


void *thr_fn3(void *arg)
{
	while(1) {
		printf("thread 3 writing\n");
		sleep(1);
	}
}


int main()
{
	pthread_t tid;
	void *retval;

	pthread_create(&tid, NULL, thr_fn1, NULL);
	pthread_join(tid, &retval);
	printf("thread 1 exit code %d\n", (int)retval);	
	
	pthread_create(&tid, NULL, thr_fn2, NULL);
	pthread_join(tid, &retval);
	printf("thread 2 exit code %d\n", (int)retval);

	pthread_create(&tid, NULL, thr_fn3, NULL);
	sleep(3);
	// 调用pthread_cancel函数取消第三个线程
	pthread_cancel(tid);
	// 如果线程是通过pthread_cancel异常终止掉,retval所指向的单元里存放的是常数PTHREAD_CANCELED
	pthread_join(tid, &retval);
	printf("thread 3 exit code %d\n", (int)retval);
	
	return 0;
}
