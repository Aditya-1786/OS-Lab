#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
int main(){
	int ppid = getppid();
	int pid = fork();
	printf("Child says my id %d, my Parent is %u, my grandparent is %u\n",getpid(),getppid(),ppid);
	if(pid)
	{	
		printf("Parent says my id %d, my child is %u, my parent is %u\n",getpid(),pid,getppid());
	}

}

