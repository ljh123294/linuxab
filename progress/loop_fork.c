#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>

int main(int argc, char *argv[])
{
	int i;
	pid_t pid;
	for(i=0; i < 5; ++i)
	{
		if(fork()==0)
			break;
	}
	if(5 == i)
	{
		sleep(i);
		printf("i am parent\n");
	}
	else{
		sleep(i);
		printf("i am %dth child\n", i+1);
	}
}
