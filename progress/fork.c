#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<error.h>

int main(int argc, char *argv[])
{
	pid_t pid=fork();
	if(pid == -1)
	{
		perror("fork error");
		exit(1);
	}
	else if(pid == 0)
	{
		printf("i am child, pid = %d, parent id = %d\n",getpid(),getppid());
	}
	else if(pid > 0)
	{
		printf("i am parent, id = %d, child id = %d\n",getpid(),pid);
	}
	printf("==================\n");
}
