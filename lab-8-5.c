#include<string.h>
#include<signal.h>
#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
int main(){
 char buf[10];
 while(1)
 { printf("\nEnter a word:");
 fgets(buf,10,stdin);
 if(!strncmp(buf,"quit",4))raise(SIGINT);// compare if input is "quit"
 }
}
