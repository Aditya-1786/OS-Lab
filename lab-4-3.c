#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
int main(){
int pid=fork();
if(!pid){
execl("lab-3-1a","lab-3-1a",NULL);
int status,child_id;
child_id = wait(&status);
if(WIFEXITED(status)) printf("Exit code %d\n",WEXITSTATUS(status));
}
}

