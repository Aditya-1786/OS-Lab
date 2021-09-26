#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
int main(){
	int pid = fork();
	if(!pid){
		printf("My id is %u, my Parent id is %u\n",getpid(),getppid());
		exit(8);
	}
	else{
		int child_id,status;
		child_id=wait(&status);
		printf("Process %u terminated.\n",child_id);
		if(WIFEXITED(status))
		{
			printf("Child exit code %u\n",WEXITSTATUS(status));
		}
	}
}
