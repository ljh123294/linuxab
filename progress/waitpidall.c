#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int main(int argc, char *argv[])
{
	pid_t pid,wpid;
	int i;
	for(i=0;i<5 ;++i){
		if(fork()==0){
			break;
		}
	}
	if(i==5){
//		while((pid=waitpid(-1,NULL,WNOHANG))!=-1){
//			sleep(1);
//			printf("wait child whose id is %d\n",pid);

		while((pid=waitpid(-1,NULL,0))!=-1){
			printf("wait child whose id is %d\n",pid);
		}
	}
	else{
		sleep(i);
		printf("i am %dth child, pid is %d\n",i+1, getpid());
	}
}
