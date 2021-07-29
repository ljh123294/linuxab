#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<pthread.h>

pthread_mutex_t mutex;
void *tfun(void *args)
{
	srand(time(NULL));
	while(1){
		pthread_mutex_lock(&mutex);
		printf("hello ");
		sleep(rand() % 2);
		printf("world\n");
		pthread_mutex_unlock(&mutex);
		sleep(rand() % 2);
	}
	return NULL;
}
int main(int argc, char *argv[])
{
	int ret = pthread_mutex_init(&mutex, NULL);
	if(0 != ret){
		fprintf(stderr, "pthread_mutex_init error: %s\n", strerror(ret));
		exit(1);
	}
	pthread_t tid = pthread_create(&tid, NULL, tfun, NULL);
	srand(time(NULL));
	while(1){
		pthread_mutex_lock(&mutex);
		printf("HELLO ");
		sleep(rand() % 2);
		printf("WORLD\n");
		pthread_mutex_unlock(&mutex);
		sleep(rand() % 2);
	}
	pthread_join(tid, NULL);
	pthread_mutex_destroy(&mutex);
}
