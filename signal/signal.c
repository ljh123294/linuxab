#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<signal.h>

void sig_cath(int signo){
	printf("catch signo %d\n", signo);
}
int main(int argc, char *argv[])
{
	signal(SIGINT, sig_cath);
	while(1);
}
