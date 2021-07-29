#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<pthread.h>

void *tfun(void *arg)
{
	int i = (int)arg;
	sleep(i);
	printf("i am %dth thread: pid = %d, tid = %lu\n", i+1, getpid(), pthread_self());

	return NULL;
}
int main(int argc, char *argv[])
{
	int i;
	int ret;
	pthread_t tid;

	for(i = 0; i < 5; ++i){
		ret = pthread_create(&tid, NULL, tfun, (void *)i);
		if(0 != ret){
			perror("pthread_create error");
			exit(1);
		}
	}
	sleep(i);
	printf("i am main: pid = %d, tid = %lu\n", getpid(), pthread_self());
}
