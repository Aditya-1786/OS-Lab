#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
int main()
{
	int pid,i;
	pid = fork();
	for(i=0;i<5;i++)
	{
		if(pid==0)
		{
			printf("Child id = %u, Parent id = %u\n",getpid(),getppid());
			pid=fork();
		}
		
		else
			wait(NULL);	
	}
}
