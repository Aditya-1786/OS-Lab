#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
void *fun1(void *);
void *fun2(void *);
int NUM=100;
int main(){
pthread_t t1,t2;
pthread_create(&t1,NULL,fun1, (void *)NULL);
pthread_create(&t2, NULL, fun2, (void *)NULL);
pthread_join(t1,NULL);
pthread_join(t2,NULL);
}
void *fun1(void *m)
{
while(1 )
{
NUM=NUM+5;
printf("I am %lu - number%d \n",pthread_self(),NUM);
usleep(rand()%2000000);
if(NUM>120 || NUM <80)break;
}
}
void *fun2(void *m)
{
while(1 )
{
NUM=NUM-5;
printf("I am %lu - number%d \n",pthread_self(),NUM);
usleep(rand()%2000000);
if(NUM>120 || NUM <80)break;
}
}
