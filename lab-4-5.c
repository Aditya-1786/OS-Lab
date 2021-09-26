#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
int main(){
int a=5,b=10;
int pid=fork();
if(!pid){
sleep(3);
a+=5;
printf("Child a=%d b=%d\n",a,b);
sleep(4);
b+=10;
printf("Child a=%d b=%d\n",a,b);
}
else{
sleep(1);
a+=15;
printf("Parent a=%d b=%d\n",a,b);
sleep(2);
b+=5;printf("Parent a=%d b=%d\n",a,b);
}
}

