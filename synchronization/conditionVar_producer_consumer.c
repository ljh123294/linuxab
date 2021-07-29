#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
#include<sys/wait.h>

struct msg{
	int num;
	struct msg *next;
};

struct msg *head = NULL;

pthread_cond_t has_product = PTHREAD_COND_INITIALIZER;
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

void *consumer(void *arg){
	struct msg *mp;
	while(1){
		pthread_mutex_lock(&lock);
		while(NULL == head){
			pthread_cond_wait(&has_product, &lock);
		}
		mp = head;
		head = head->next;
		pthread_mutex_unlock(&lock);
		printf("---------consume %d\n", mp->num);
		free(mp);
		sleep(rand()%2);
	}
}

void *producer(void *arg){
	struct msg *mp;
	while(1){
		mp = malloc(sizeof(struct msg));
		mp->num = rand()%100;
		printf("produce %d\n", mp->num);
		pthread_mutex_lock(&lock);
		mp->next = head;
		head = mp;
		pthread_mutex_unlock(&lock);
		pthread_cond_signal(&has_product);
		sleep(rand()%3);
	}
}

int main(int argc, char *argv[])
{
	pthread_t proid, conid;
	srand(time(NULL));
	pthread_create(&proid, NULL, producer, NULL);
	pthread_create(&conid, NULL, consumer, NULL);
	pthread_join(proid, NULL);
	pthread_join(proid, NULL);
	pthread_mutex_destroy(&lock);
	pthread_cond_destroy(&has_product);
}
