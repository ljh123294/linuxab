#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int main(int argc, char *argv[])
{
	int i;
	pid_t pid,child2thpid,wpid;
	for(i=0; i < 5; ++i)
	{
		pid = fork();
		if(pid==0)
			break;
		if(i==1){
			child2thpid=pid;
		}
	}
	if(5 == i)
	{
		sleep(1);
		printf("i am waiting 2th child whose id id %d\n",child2thpid);
		wpid = waitpid(child2thpid,NULL,WNOHANG);
		if(wpid == -1){
			perror("waitpid error\n");
			exit(0);
		}
		else if(wpid == 0){
			printf("i can't wait any more\n");
		}
		else{
			printf("success wait\n");
		}
	}
	else{
		printf("i am %dth child, my pid is %d\n", i+1, getpid());
	}
}
