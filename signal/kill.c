#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<signal.h>
#include<sys/wait.h>
#include<fcntl.h>

int main(int argc, char *argv[])
{
	pid_t pid = fork();
	if(pid == 0){
		printf("child pid = %d, ppid = %d\n", getpid(), getppid());
		sleep(2);
		kill(getppid(), SIGCHLD);
		while(1);
	}
	else if(pid > 0){
		while(1){
			printf("parent pid = %d\n", getpid());
			sleep(1);
		}
	}
}
