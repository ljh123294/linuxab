#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/time.h>

int main(int argc, char *argv[])
{
	struct itimerval it, oldit;
	it.it_value.tv_sec = 1;
	it.it_value.tv_usec = 0;
	it.it_interval.tv_sec = 0;
	it.it_interval.tv_usec = 0;
	if(setitimer(ITIMER_REAL, &it, &oldit) == -1){
		perror("setitimer error");
		exit(1);
	}
	int i = 0;
	while(1)
		printf("i = %d\n", ++i);

}
