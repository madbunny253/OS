#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<pthread.h>
#include<semaphore.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<fcntl.h>

char *fifo1 = "myfifos";
char *fifo2 = "yourfifios";
	
	
int main(int argc,char *argv[])
{
	int fd1,fd2;
	char send[50];
	int info[3];
	mkfifo(fifo1,0777);
	mkfifo(fifo2,0777);
	
	while(1)
	{
		fd1= open(fifo1,O_WRONLY);
		
		printf("\nEnter ip: ");
		fgets(send,50,stdin);
		
		write(fd1,send,50);
		
		close(fd1);
		
		fd2= open(fifo2, O_RDONLY);
		read(fd2,info,sizeof(info));
		
		
		printf("\nC2: %d\tW: %d\tL: %d",info[0],info[1],info[2]);
		close(fd2);
	
	}
		
	printf("\nCode Eleven\n");
}
