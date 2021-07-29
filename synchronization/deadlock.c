#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<pthread.h>

pthread_mutex_t mutex1,mutex2;

void *tfun1(void *arg)
{
	pthread_mutex_lock(&mutex1);
	printf("acquire lock1\n");
	pthread_mutex_lock(&mutex2);
	printf("acquire lock2\n");
	pthread_mutex_unlock(&mutex1);
	pthread_mutex_unlock(&mutex2);
	return NULL;
}

void *tfun2(void *arg)
{
	pthread_mutex_lock(&mutex2);
	printf("acquire lock2\n");
	pthread_mutex_lock(&mutex1);
	printf("acquire lock1\n");
	pthread_mutex_unlock(&mutex2);
	pthread_mutex_unlock(&mutex1);
	return NULL;
}
int main(int argc, char *argv[])
{
	pthread_mutex_init(&mutex1, NULL);
	pthread_mutex_init(&mutex2, NULL);

	pthread_t tid[2];
	pthread_create(&tid[0], NULL, tfun1, NULL);
	pthread_create(&tid[1], NULL, tfun2, NULL);
	pthread_join(tid[0], NULL);
	pthread_join(tid[1], NULL);
}
