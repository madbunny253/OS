//1
#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<unistd.h>



int main(int argc,char *argv[])
{

	printf("This is from FIRST program\nThis is normal array\n");
	
	for(int i=0;i<argc;i++)
	{
		printf("%s\t",argv[i]);
	}
	
	
	
	pid_t pid;
	pid = fork();
		
	if(pid == 0)
	{
		printf(" process id is %d \n",getpid());
		printf("child parent process id is %d \n",getppid());
		execv(argv[1],argv);
		 
	}
	
	
	else
	{
		wait(NULL);
		
		printf(" process id is %d \n",getpid());
		printf("parent process id is %d \n",getppid());
	}
} 

//2
#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<unistd.h>



int main(int argc,char *argv[])
{
	printf("This is from different program\n");
	
	//n = argc
	//array = argv
	
	char *temp;
	for(int i=2;i<argc;i++)
	{
		for(int j=2;j<argc-1;j++)
		{
			if(atoi(argv[j])>atoi(argv[j+1]))
			{
				temp = argv[j];
				argv[j]=argv[j+1];
				argv[j+1]=temp;
			}
		}
	}
	
	printf("Printed Sorted Array\n");
	for(int i=1;i<argc;i++)
	{
		printf("%s\t",argv[i]);
	}	
} 
