//1
#include<stdio.h>
#include<string.h>
#include<fcntl.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/stat.h>
#include<stdlib.h>

int main()
{
	int fd1,fd2;
	char * fifo1="fifo1";
	char * fifo2="fifo2";
	mkfifo(fifo1,0666);
	mkfifo(fifo2,0666);
	while(1)
	{
		FILE * fp;
		fd1=open(fifo1,O_WRONLY);
		fp=fdopen(fd1,"w");
		char sent[100];
		printf("Enter Sentence:");
		fgets(sent,sizeof(sent),stdin);
		fprintf(fp,"%s",sent);
		fclose(fp);
		
		fd2=open(fifo2,O_RDONLY);
		fp=fdopen(fd2,"r");
		char cont[100];
		fgets(cont,sizeof(cont),fp);
		printf("%s",cont);
		fclose(fp);
		return 0;
	}
}	

//2
#include<stdio.h>
#include<string.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>

int main()
{
	int fd1,fd2;
	char * fifo1="fifo1";
	char * fifo2="fifo2";
	mkfifo(fifo1,0777);
	mkfifo(fifo2,0777);
	while(1)
	{
		FILE * fp;
		fd1=open(fifo1,O_RDONLY);
		fp=fdopen(fd1,"r");
		char sent[100];
		fgets(sent,sizeof(sent),fp);
		fclose(fp);
		
		int cc=0,wc=0,lc=0;
		for(int i=0;sent[i] != '\0';i++)
		{
			cc++;
			if(sent[i]==' ' || sent[i]=='\t' || sent[i]=='\n')
			{
				wc++;
			}
			if(sent[i]=='\n')
			{
				lc++;
			}
		}
		
		FILE * output=fopen("output.txt","w");
		fprintf(output,"Characters:%d \nWord:%d \nLines:%d\n",cc,wc,lc);
		fclose(fp);
		
		fd2=open(fifo2,O_WRONLY);
		fp=fdopen(fd2,"w");
		
		output=fopen("output.txt","r");
		char cont[100];
		fgets(cont,sizeof(cont),output);
		fprintf(fp,"%s",cont);
		fclose(fp);
		fclose(output);
	}
	return 0;
}
