#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>

int main(int argc, char *argv[])
{
	pid_t pid=fork();
	if(pid == 0)
	{
		execlp("ls","ls","-l","-d","-h",NULL);
		perror("execlp error");
		exit(0);
	}
	else{
		sleep(1);
		printf("i am parent");
	}
}
