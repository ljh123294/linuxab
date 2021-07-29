#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<signal.h>

void sig_cath(int signo){
	printf("catch signo %d\n", signo);
	sleep(3);
}
int main(int argc, char *argv[])
{
	struct sigaction act, oldact;
	act.sa_handler = sig_cath;
	sigemptyset(&act.sa_mask);
	sigaddset(&act.sa_mask, SIGQUIT);
	act.sa_flags = 0;
	int ret = sigaction(SIGINT, &act, &oldact);
	if(ret == -1){
		perror("sigaction error");
		exit(1);
	}
	//ret = sigaction(SIGQUIT, &act, &oldact);
	while(1);
}
