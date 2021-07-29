#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<pthread.h>

pthread_rwlock_t rwlock;
int counter = 0;

void *pth_write(void *arg)
{
	int i = (int)arg;
	int t;
	while(1){
		pthread_rwlock_wrlock(&rwlock);
		t = counter;
		usleep(1000);
		printf("write no: %d, tid: %lu, counter: %d, ++counter: %d\n", i, pthread_self(), t, ++counter);
		pthread_rwlock_unlock(&rwlock);
		usleep(200000);
	}
}
void *pth_read(void *arg)
{
	int i = (int)arg;
	while(1){
		pthread_rwlock_rdlock(&rwlock);
		printf("read no: %d, tid: %lu,counter: %d\n", i, pthread_self(), counter);
		pthread_rwlock_unlock(&rwlock);
		usleep(200000);
	}
}

int main(int argc, char *argv[])
{
	pthread_t tid[8];
	pthread_rwlock_init(&rwlock, NULL);
	int i;
	for(i = 0; i < 3; ++i){
		pthread_create(&tid[i], NULL, pth_write, (void *)i);
	}
	for(i = 0; i < 5; ++i){
		pthread_create(&tid[i+3], NULL, pth_read, (void *)i);
	}
	for(i = 0; i < 8; ++i){
		pthread_join(tid[i], NULL);
	}
	pthread_rwlock_destroy(&rwlock);
}
