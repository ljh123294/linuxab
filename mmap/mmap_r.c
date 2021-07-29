#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<fcntl.h>
#include<sys/mman.h>
#include<string.h>

struct student{
	int id;
	char name[256];
	int age;
};
int main(int argc, char *argv[]){
	int fd = open("/dev/zero", O_RDONLY);
	struct student stu;
	struct student *p = mmap(NULL, sizeof(stu), PROT_READ, MAP_SHARED, fd, 0);
	if(p == MAP_FAILED){
		perror("mmap error");
		exit(1);
	}
	while(1){
		printf("student id is %d, name is %s, age id %d\n", p->id, p->name, p->age);
		sleep(1);
	}
	int ret = munmap(p, 4);
	if(ret == -1){
		perror("munmmap error");
		exit(1);
	}
}

