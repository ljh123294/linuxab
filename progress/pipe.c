#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<string.h>

int main(int argc, char *argv[])
{
	int ret;
	int fd[2];
	pid_t pid;
	char buff[1024];
	char *str="hello pipe\n";

	ret=pipe(fd);
	if(ret==-1){
		perror("pipe errpr");
		exit(1);
	}
	pid=fork();
	if(pid>0){
		close(fd[1]);
		ret= read(fd[0],buff,sizeof(buff));
		write(STDOUT_FILENO,buff,ret);
		close(fd[0]);
	}
	else if(pid==0){
		close(fd[0]);
		write(fd[1],str,strlen(str));
		close(fd[1]);
	}
}
