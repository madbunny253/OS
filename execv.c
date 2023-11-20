//1
#include<sys/types.h>
#include<unistd.h>
#include<stdio.h>
int main(int argc , char *argv[])
{
    pid_t processid;
    int n=argc;
    processid=fork();
    if( processid==0 )
    {
        printf("\nChild process id : %d \n",getpid());
        printf("\nChild Parent process id : %d \n",getppid());
        char* array[argc];
        //store the elements into the array (command line arguments)
        int k;
        for(k=1 ; k<argc+1 ; k++)
        {
            array[k-1] = argv[k];
        }
        printf("\nThe elements stored in array (before sorting) :\n");
        for(int q=2 ; q<argc ;q++)
        {
            printf("%d\n",atoi(array[q-1]));
        }
        char* temp;
        for(int i=1;i<n-1;i++)
        {
            for(int j=1;j<n-i-1;j++)
            {
                if( atoi(array[j]) > atoi(array[j+1]) )
                {
                    temp=array[j];
                    array[j]=array[j+1];
                    array[j+1]=temp;
                }
            }
        }
        //inserting NULL at the end of the array.
        array[k]=NULL;
        //execl()to pass a list
        //execv() to pass a vector
        execv(array[0],array);
    }
    else
    {
        wait();
        printf("\nParent process id : %d",getpid());
        printf("\nParent parent process id : %d",getppid());
    }
}

//2
#include <stdio.h>
#include <stdlib.h>
#include<sys/types.h>
int main(int argc , char *argv[])
{
    int i;
    int array[argc];
    //store the elements into the array (command line arguments)
    for(int i=1 ; i<argc ; i++)
    {
        array[i-1] = atoi(argv[i]);
    }
    printf("\nThe elements stored in array (after sorting ) are :\n");
    for(int i=1; i<argc ;i++)
    {
     printf("%d\n",array[i-1]);
    }
    int search;
    printf("Enter the target to search : ");
    scanf("%d",&search);
    int low = 0;
    int high = argc-1;
    int found=0;
    while ( low <= high)
    {
        //int mid =low + (high - low) / 2;
        int mid =(high + low) / 2;
        if (array[mid] == search)
        {
            printf("\nElement Found at index: %d \n", mid);
            printf("\nB process id : %d \n",getpid());
            printf("\nB Parent process id : %d \n",getppid());
            found=1;
            break;
        }
        else if (array[mid] < search)
        {
         low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    if(found==0)
    {
        printf("\nThe element %d is not present in the given array !!!\n",search);
    }
    return 0;
}
