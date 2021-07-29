#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>

int main(int argc, char *argv[])
{
	pid_t pid = fork();
	if(pid == -1){
		perror("fork error");
		exit(1);
	}
	if(pid > 0){
		exit(0);
	}
	pid = setsid();
	int ret = chdir("/home/lin/CPPcode/linuxab");
	if(ret == -1){
		perror("chdir error");
		exit(1);
	}
	umask(0002);
	close(STDIN_FILENO);
	int fd = open("/dev/null", O_RDWR);
	dup2(fd, STDOUT_FILENO);
	dup2(fd, STDERR_FILENO);
	while(1);

}
