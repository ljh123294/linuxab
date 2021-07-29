#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<sys/mman.h>
#include<sys/wait.h>
#include<fcntl.h>

int main(int argc, char *argv[])
{
	int fd = open("Anumber", O_RDWR| O_CREAT| O_TRUNC, 0644);
	ftruncate(fd, 4);
	int len = lseek(fd, 0, SEEK_END);
	int *p = (int *)mmap(NULL, len, PROT_READ| PROT_WRITE, MAP_SHARED, fd, 0);
	close(fd);
	if(p == MAP_FAILED){
		perror("mmap error");
		exit(1);
	}
	int var = 100;
	pid_t pid = fork();
	if(pid == 0){
		*p = 2000;
		var = 200;
		printf("child, *p = %d, var = %d\n", *p, var);
	}
	else{
		sleep(1);
		printf("parent, *p = %d, var = %d\n", *p, var);
		wait(NULL);
		int ret = munmap(p, 4);
		if(ret == -1){
			perror("munmap error");
			exit(1);
		}
	}
}
