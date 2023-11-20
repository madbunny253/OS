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
	int lc=0,wc=0,cc=0;
	char recv[50];
	int info[3];
	mkfifo(fifo1,0777);
	mkfifo(fifo2,0777);

	
	while(1)
	{
		fd1= open(fifo1,O_RDONLY);
		
		read(fd1,recv,sizeof(recv));
		printf("%s",recv);
		
		close(fd1);
		
		for(int i=0;recv[i]!='\0';i++)
		{
			if(recv[i]==' ' || recv[i]=='\n')
			{wc++;
			if(recv[i]=='\n')
			{lc++;}
			}
			else
			{cc++;}
		}
		
		info[0] = cc;
		info[1] = wc;
		info[2] = lc++;
		printf("\nC1: %d\tW: %d\tL: %d",info[0],info[1],info[2]);
		fd2 = open(fifo2,O_WRONLY);
		write(fd2,info,sizeof(info));
		close(fd2);	
	
	}
		
	printf("\nCode Eleven\n");
}
