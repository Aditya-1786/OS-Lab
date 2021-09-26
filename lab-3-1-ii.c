#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>

int main(){
	int pid = fork();
	switch(pid){
		case 0:{
			printf("My id is %u, my parent id is %u\n",getpid(),getppid());
			break;
		}
		default:{
			printf("My id is %u, my parent id is %u\n",getpid(),getppid());	
		break;		
		}
	}
}
