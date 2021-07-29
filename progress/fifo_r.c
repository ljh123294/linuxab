#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main(int argc, char *argv[])
{
	char buf[4096];
	int fd = open(argv[1], O_RDONLY);
	if(fd < 0){
		perror("open error");
		exit(1);
	}
	int ret;
	while(1){
		ret = read(fd, buf, sizeof(buf));
		write(STDOUT_FILENO, buf, ret);
	}
}
