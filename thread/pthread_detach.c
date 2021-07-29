#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
#include<string.h>

void *tfun(void *arg){
	printf("thread: pid = %d, tid = %lu\n", getpid(), pthread_self());
	return NULL;
}
int main(int argc, char *argv[])
{
	printf("main: pid = %d, tid = %lu\n", getpid(), pthread_self());
	pthread_t tid;
	int ret = pthread_create(&tid, NULL, tfun, NULL);
	if(0 != ret){
		fprintf(stderr, "pthread_create error: %s\n", strerror(ret));	
		exit(1);
	}
	ret = pthread_detach(tid);
	if(0 != ret){
		fprintf(stderr, "pthread_detach error: %s\n", strerror(ret));	
		exit(1);
	}
	sleep(1);
	ret = pthread_join(tid, NULL);
	if(0 != ret){
		fprintf(stderr, "pthread_join error: %s\n", strerror(ret));	
		exit(1);
	}

	pthread_exit(NULL);
}
