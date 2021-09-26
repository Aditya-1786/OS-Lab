#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
int main(){
int pid=fork();
if(!pid){
execlp("ls","ls","-l","-a",NULL);
}
else{
execlp("date","date",NULL);
}
}

