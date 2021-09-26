#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
int main(int argc,char* argv[]){
int pid=fork();
if(!pid){
execlp(argv[1],argv[1],argv[2],argv[3],0);
}
else{execlp(argv[4],argv[4],NULL);
}
}
