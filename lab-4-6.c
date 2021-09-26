#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
int main(int argc,char *argv[]){
printf("Number of arguments are %d\n",argc);
int i=1;
while(--argc){
printf("CLI string %d: %s \n",i,argv[i]);
i++;
}
}

