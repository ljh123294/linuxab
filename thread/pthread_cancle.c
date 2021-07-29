#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
#include<string.h>

void *tfun(void *arg)
{
	while(1){
		//printf("thread pid = %d, tid = %lu\n", getpid(), pthread_self());
		//sleep(1);
		pthread_testcancel();
	}
	return NULL;
}

int main(int argc, char *argv[])
{
	pthread_t tid;
	int ret = pthread_create(&tid, NULL, tfun, NULL);
	if(0 != ret){
		fprintf(stderr, "pthread_create error:%s\n", strerror(ret));
		exit(1);
	}
	printf("main thread ptid = %d, tid = %lu\n", getpid(), pthread_self());
	//sleep(1);
	ret = pthread_cancel(tid);
	printf("----\n");
	if(0 != ret){
		fprintf(stderr, "pthread_cancel error:%s\n", strerror(ret));
		exit(1);
	}
	while(1);
	pthread_exit(NULL);
}
