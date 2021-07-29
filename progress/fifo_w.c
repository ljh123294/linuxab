#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<fcntl.h>

int main(int argc, char *argv[])
{
	char buf[4096];
	int fd = open(argv[1], O_WRONLY);
	if(fd < 0){
		perror("open error");
		exit(1);
	}
	int i = 0;
	while(1){
		sprintf(buf, "hello fifo %d\n", ++i);
		write(fd, buf, strlen(buf));
		sleep(1);
	}
	close(fd);
}
