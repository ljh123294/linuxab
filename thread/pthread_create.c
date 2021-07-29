#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<pthread.h>

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
		perror("pthread_create error");
		exit(1);
	}
	//sleep(1);
	pthread_exit(NULL);
}
