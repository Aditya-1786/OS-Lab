#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
int main(){
	int pid = fork();
	if(!pid){
		printf("My id is %u, my parent id is %u\n",getpid(),getppid());
	
	}
	else{
		printf("My id is %u, my parent id is %u\n",getpid(),getppid());
	}	
}
