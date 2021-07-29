#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int main(int argc, char *argv[])
{
	int fd[2];
	int ret = pipe(fd);
	int i;
	for(i=0;i<2;++i){
		if(fork()==0){
			break;
		}
	}
	if(i == 0){
		close(fd[0]);
		dup2(fd[1],STDOUT_FILENO);
		execlp("ls","ls",NULL);
	}
	if(i == 1){
		close(fd[1]);
		dup2(fd[0],STDIN_FILENO);
		execlp("wc","wc","-l",NULL);
	}
	if(i == 2){
		close(fd[1]);
		close(fd[2]);
		wait(NULL);
		wait(NULL);
	}
}
