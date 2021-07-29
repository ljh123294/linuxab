#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<sys/stat.h>

int main(int argc, char *argv[])
{
	int ret = mkfifo("mytestfifo", 0664);
	if(ret == -1){
		perror("mkfifo fail");
		exit(1);
	}
}
