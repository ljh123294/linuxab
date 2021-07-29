#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>

int main(int argc, char *argv[])
{
	int fd[2];
	int ret=pipe(fd);
	pid_t pid=fork();
	if(pid==0){
		close(fd[0]);
		dup2(fd[1],STDOUT_FILENO);
		execlp("ls","ls",NULL);
	}
	else if(pid > 0){
		close(fd[1]);
		dup2(fd[0],STDIN_FILENO);
		execlp("wc","wc","-l",NULL);
	}
}
