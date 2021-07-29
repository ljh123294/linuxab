#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<fcntl.h>
#include<sys/mman.h>

int main(int argc, char *argv[])
{
	int fd = open("testmmap", O_RDWR| O_CREAT| O_TRUNC, 0644);
	ftruncate(fd, 20);
	int len = lseek(fd, 0, SEEK_END);
	int len = 0;
	char *p = mmap(NULL, len, PROT_READ| PROT_WRITE, MAP_SHARED, fd, 0);
	if(p == MAP_FAILED){
		perror("mmap error");
		exit(1);
	}
	strcpy(p, "hello, mmap");
	printf("---%s\n", p);
	int ret = munmap(p, len);
	if(ret == -1){
		perror("munmap error");
		exit(1);
	}
	close(fd);
}
