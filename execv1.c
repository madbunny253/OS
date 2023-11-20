#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<unistd.h>



int main(int argc,char *argv[])
{

	printf("This is from FIRST program\nThis is normal array\n");
	
	for(int i=2;i<argc;i++)
	{
		printf("%s\t",argv[i]);
	}
	execv(argv[1],argv);
}
