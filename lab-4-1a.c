#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
int main(){
	int pid = fork();
	if(!pid){
		printf("child pid %u its parent id %u \n",getpid(),getppid());
		execl("/bin/ls","ls",0,NULL);
}
else{
	int status,child_id;
	child_id = wait(&status);
	printf("\n%u",child_id);
	if(WIFEXITED(status)){
		printf("\nChild exit code %u",WEXITSTATUS(status));
}
}
}

