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

	pthread_attr_t attr;
	int ret = pthread_attr_init(&attr);
	if(0 != ret){
		fprintf(stderr, "pthread_attr_init error: %s\n", strerror(ret));
		exit(1);
	}

	ret = pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
	if(0 != ret){
		fprintf(stderr, "pthread_attr_setdetachstate error: %s\n", strerror(ret));
		exit(1);
	}
	
	pthread_t tid;
	ret = pthread_create(&tid, &attr, tfun, NULL);
	if(0 != ret){
		fprintf(stderr, "pthread_create error: %s\n", strerror(ret));
		exit(1);
	}

	ret = pthread_attr_destroy(&attr);
	if(0 != ret){
		fprintf(stderr, "pthread_destroy error: %s\n", strerror(ret));
		exit(1);
	}

	sleep(1);

	ret = pthread_join(tid, NULL);
	if(0 != ret){
		fprintf(stderr, "pthread_destroy error: %s\n", strerror(ret));
		exit(1);
	}

	pthread_exit(NULL);
}
