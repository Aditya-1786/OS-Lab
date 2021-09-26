#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
int main(){
int pid=fork();
if(!pid){
execl("lab-4-3","lab-4-3",NULL);
}
}

