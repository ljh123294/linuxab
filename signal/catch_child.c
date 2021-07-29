#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<signal.h>
#include<sys/wait.h>

void catch_child(int signo){
	pid_t pid;
	int status;
	while((pid = waitpid(-1, &status, 0)) != -1){
		if(WIFEXITED(status))
			printf("---------------catch child id %d, ret = %d\n", pid, WEXITSTATUS(status));
	}
	return;
}

int main(int argc, char *argv[])
{
	sigset_t set;
	sigemptyset(&set);
	sigaddset(&set, SIGCHLD);
	sigprocmask(SIG_BLOCK, &set, NULL);

	int i;
	for(i = 0; i < 15; ++i){
		if(fork() == 0)
			break;
	}
	if(15 == i){
		struct sigaction act;
		act.sa_handler = catch_child;
		sigemptyset(&act.sa_mask);
		act.sa_flags = 0;
		int ret = sigaction(SIGCHLD, &act, NULL);
		
		sigprocmask(SIG_UNBLOCK, &set, NULL);
		
		if(ret == -1){
			perror("sigaction error");
			exit(1);
		}
		while(1);
	}
	else{
		printf("%dth child pid %d\n", i+1, getpid());
		return i+1;
	}
}
