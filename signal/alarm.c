#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>

int main(int argc, char *argv[])
{
	alarm(1);
	int i = 0;
	while(1){
		printf("i = %d\n", ++i);
	}
}
