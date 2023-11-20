#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<unistd.h>

int main(int argc,char *argv[])
{
	printf("This is from different program\n");
	
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
