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
	int fd = open("/dev/zero", O_RDWR| O_CREAT| O_TRUNC, 0664);
	struct student stu = {10, "xiaoming", 18};
	ftruncate(fd, sizeof(stu));
	struct student *p = mmap(NULL, sizeof(stu), PROT_READ| PROT_WRITE, MAP_SHARED, fd, 0);
	if(p == MAP_FAILED){
		perror("mmap error");
		exit(1);
	}
	while(1){
		memcpy(p, &stu, sizeof(stu));
		++stu.id;
		sleep(1);
	}
	int ret = munmap(p, 4);
	if(ret == -1){
		perror("munmmap error");
		exit(1);
	}
}

