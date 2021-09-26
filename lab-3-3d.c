#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
int main(){
	int pid = fork();
	if(!pid){
		printf("My id is %u, my Parent id is %u\n",getpid(),getppid());
		sleep(30);
	}
	else{
		printf("My id is %u, my Parent id is %u\n",getpid(),getppid());
		wait(0);
	}
}
