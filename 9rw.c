#include<unistd.h>
#include<semaphore.h>
#include<pthread.h>
#include<stdio.h>

int book[5];
sem_t r,w;
int rdcnt;

void * reader(void * arg)
{
	sem_wait(&r);
	rdcnt++;
	if(rdcnt==1)
	{
		sem_wait(&w);
	}
	sem_post(&r);
	
	printf("\nReader is reading!!");
	printf("\nThread ID:%ld",pthread_self());
	
	sem_wait(&r);
	rdcnt--;
	if(rdcnt==0)
	{
		sem_post(&w);
	}
	sem_post(&r);
}

void * writer(void * arg)
{
	sem_wait(&w);
	printf("\nWriter is writing!!");
	printf("\nThread ID:%ld",pthread_self());
	sem_post(&w);
}

int main()
{
	pthread_t wrt[5],rd[5];
	sem_init(&r,0,1);
	sem_init(&w,0,1);
	
	for(int i=0;i<5;i++)
	{
		pthread_create(&wrt[i],NULL,writer,NULL);
	}
	for(int i=0;i<5;i++)
	{
		pthread_create(&rd[i],NULL,reader,NULL);
	}
	for(int i=0;i<5;i++)
	{
		pthread_join(wrt[i],NULL);
		pthread_join(rd[i],NULL);
	}
	return 0;
}
