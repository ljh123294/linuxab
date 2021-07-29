#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int main(int argc, char *argv[])
{
	pid_t pid,wpid;
	int status;
	pid= fork();
	if(pid==0){
		printf("i am child, i am going to sleep 10s\n");
		sleep(20);
		printf("-------child die----------\n");
		return 77;
	}
	else if(pid>0){
		wpid=wait(&status);
		if(wpid==-1){
			perror("wait error");
			exit(1);
		}
		if(WIFEXITED(status)){
			printf("child exit with %d\n",WEXITSTATUS(status));
		}
		if(WIFSIGNALED(status)){
			printf("child was killed with signal %d\n",WTERMSIG(status));
		}
		printf("-------parent wait finish-------------\n");
	}
	else{
		perror("fork error");
	}
}
