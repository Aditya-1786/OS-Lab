#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
int main(int argc ,char* argv[]){
int j,childpid;
for(j=0;j<3;j+=1){
switch(fork()){
 case 0: printf("Child %d started with PID %ld,sleeping \n",j,(long)getpid());
 sleep(1+j*2);
 exit(0);
 default:break;
}}
for(;;){
childpid=wait(NULL);
if(childpid==-1){printf("No more child \n");exit(EXIT_SUCCESS);}
printf("wait() returned child PID %ld \n",(long) childpid);
}
}
