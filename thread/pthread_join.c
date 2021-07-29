#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
#include<string.h>

struct student{
	int age;
	char name[256];
};

void *tfun(void *arg)
{
	struct student *stu = malloc(sizeof(struct student));
	stu->age = 18;
	strcpy(stu->name, "xiaoming");
	return (void *)stu;
}

int main(int argc, char *argv[])
{
	pthread_t tid;
	int ret = pthread_create(&tid, NULL, tfun, NULL);
	if(0 != ret){
		perror("pthread_create error");
		exit(1);
	}
	struct student *stu;
	ret = pthread_join(tid, (void **)&stu);
	if(0 != ret){
		perror("pthread_join error");
		exit(1);
	}
	printf("child thread exit with age = %d, name = %s\n", stu->age, stu->name);
}
