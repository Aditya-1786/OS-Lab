#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
#include<signal.h>
pthread_t t1,t2;
void mysignal(int signum)
{
 pthread_cancel(t1);
 printf("\n thread %lu cancelled \n",t1);
 signal(signum,SIG_IGN);
}
void *fun1(void *);
void *fun2(void *);
int NUM=150;
int main(){
signal(SIGINT,mysignal);
pthread_create(&t1,NULL,fun1, (void *)NULL);
pthread_create(&t2, NULL, fun2, (void *)NULL);
pthread_join(t1,NULL);
pthread_join(t2,NULL);
}
void *fun1(void *m)
{
while(1 )
{
NUM=NUM+10;
printf("I am %lu - number%d \n",pthread_self(),NUM);
usleep(rand()%2000000);
if(NUM<80 || NUM>250)break;
}
}
void *fun2(void *m)
{
while(1 )
{
NUM=NUM-10;
printf("I am %lu - number%d \n",pthread_self(),NUM);
usleep(rand()%2000000);
if(NUM<80 || NUM>250)break;
}
}
