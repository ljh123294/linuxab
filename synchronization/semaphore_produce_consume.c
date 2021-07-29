#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<semaphore.h>
#include<pthread.h>

#define NUM 5

int queue[NUM];
sem_t blank_number, product_number;

void *consumer(void *arg){
	int i = 0;
	while(1){
		sem_wait(&product_number);
		printf("consume %d\n", queue[i]);
		queue[i] = 0;
		sem_post(&blank_number);
		i = (i+1)%NUM;
		sleep(rand()%3);
	}
}

void *producer(void *arg){
	int i = 0;
	while(1){
		sem_wait(&blank_number);
		queue[i] = rand()%100;
		printf("---------produce %d\n", queue[i]);
		sem_post(&product_number);
		i = (i+1)%NUM;
		sleep(rand()%3);
	}
}
int main(int argc, char *argv[])
{
	sem_init(&blank_number, 0, NUM);
	sem_init(&product_number, 0, 0);
	pthread_t proid, conid;
	pthread_create(&proid, NULL, producer, NULL);
	pthread_create(&conid, NULL, consumer, NULL);
	pthread_join(proid, NULL);
	pthread_join(conid, NULL);
	sem_destroy(&blank_number);
	sem_destroy(&product_number);
}

