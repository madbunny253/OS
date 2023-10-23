//1
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>


void main(int argc, char* argv[])
{

	//const char* arr[]={"./b.out", "1", "3", "5", "7", "8", "9", NULL};
	
	char* arr[argc];
	
	for(int i=1; i<argc; i++)
	{
		arr[i-1]=argv[i];
	}
	
	/*
	printf("\nPrinting string");
	for(int i=0; i<argc-1; i++)
	{
		printf("%s ", arr[i]);
	}
	*/
	
	//Sorting array
	char* temp[argc];
	for(int i=0; i<argc-2; i++)
	{
		for(int j=1; j<argc-2-i; j++)
		{
			if(atoi(arr[j])>atoi(arr[j+1]))
			{
				temp[j]=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp[j];
			}	
		}
	}
	
	arr[argc-1]=NULL;
	
	
	/*
	printf("\nPrinting sorted string");
	for(int j=0; j<argc-1; j++)
	{
		printf("%s ", arr[j]);
	}
	*/
	
	
	pid_t pid;
	
	pid=fork();
	
	if(pid == 0)
	{
		printf("\nProcess id is: %d", getpid());
		printf("\nParent Process id is: %d \n", getppid());
		
		for(int x=1; x<argc-1; x++)
		{
			printf("%s ",arr[x]);
		}
		
		printf("\n");
		
		execv(arr[0],arr);
	}
	else
	{
		pid = wait(NULL);
		
		printf("\nProcess id is: %d", getpid());
	}


}


//2
#include<stdio.h>
#include<stdlib.h>

int binary_Search(int low, int high, int key, int array[], int f ) 
{

	int mid = low + (high - low) / 2;

	if (key == array[mid])
	{
		f=1;
		return mid;
	}
	      	
	if (key<array[mid])
	{
		return binary_Search(low,mid-1,key, array,0);
	}
		
	if (key>array[mid])
	{	
		return binary_Search(mid+1,high,key,array,0);
	}

 
}

void BinarySearch_call(int count, int array[])
{
	int key,index;
	printf("Enter key : ");
	scanf("%d", &key);
	
	index = binary_Search(0,count-1,key,array,0);
	printf("\nPresent at index : %d",index);
}	
	
void main( int argc, char* argv[])
{
	int i,a[argc-1],sum=0;
	for(i=1;i<argc;i++)
	{
		a[i-1] =atoi(argv[i]);   //atoi==ascii to interger conversion.
	}
	//printf("Addition : %d ",sum);
	
	BinarySearch_call(argc, a);
	
}		



