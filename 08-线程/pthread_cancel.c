#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

/* AsyncTask::doInBackground() */
void *run(void *arg)
{
	while(1) {
		printf("I'm sub thread, I'm running...\n");
		sleep(2);
	}
}

/*
void *cancel_thread(void *arg)
{
	printf("I'm cancel thread....\n");
	unsigned long *tid = (unsigned long *)arg;
	pthread_cancel(*tid);
}
*/


int main()
{
	
	void *ret;
	pthread_t tid, cid;
	// AsyncTask::onPrepareExecute
	printf("I'm main thread, prepare.....\n");
	pthread_create(&tid, NULL, run, NULL);	
	
	sleep(5);
	//pthread_create(&cid, NULL, cancel_thread, &tid);
	pthread_cancel(tid);
	// AsyncTask::onPostExecute
	pthread_join(tid, &ret);
	printf("I'm main thread, will end....\n");	
	printf("current return value is: %d\n", (int)ret);

	return 0;
}
