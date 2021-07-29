#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main(int argc, char *argv[])
{
	pid_t pid=fork();
	if(pid==-1){
		perror("fork error");
		exit(0);
	}
	else if(pid>0){
		int fd = open("out",O_CREAT | O_WRONLY | O_TRUNC, 0644);
		dup2(fd,STDOUT_FILENO);
		execlp("ps","ps","-aux",NULL);
	}
	else{

	}
}
