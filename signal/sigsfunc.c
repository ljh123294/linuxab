#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<signal.h>
#include<sys/wait.h>
#include<fcntl.h>

void print_set(sigset_t *set){
	for(int i = 1; i < 32; ++i){
		if(sigismember(set, i)){
			putchar('1');
		}
		else{
			putchar('0');
		}
	}
	putchar('\n');
}
int main(int argc, char *argv[])
{
	sigset_t set, oldset, pedset;
	int ret = 0;
	sigemptyset(&set);
	sigaddset(&set, SIGINT);
	sigaddset(&set, SIGQUIT);
	ret = sigprocmask(SIG_BLOCK, &set, &oldset);
	if(-1 == ret){
		perror("sigprocmask error");
		exit(1);
	}
	while(1){
	ret = sigpending(&pedset);
	if(-1 == ret){
		perror("sigpending error");
		exit(1);
	}
	print_set(&pedset);
	sleep(1);
	}

}
