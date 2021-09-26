#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
void *new_function(void *); // function to be executed concurrently by threads
int main()
{
char * buf = "I am thread 0 I am thread 1 I am thread 2 I am thread 3 I am thread 4 ";
int i;
pthread_t mythread[5];
for(i=0;i<5;i++){
pthread_create(&mythread[i], NULL, new_function, (void *)(buf + 14*i));
}
for(i=0;i<5;i++){
pthread_join(mythread[i],NULL);
}
}
// defination of function
void *new_function(void *m)
{
 char *cp = (char *) m;//type cast
 int i;
 printf("I am %ld -%s\n",pthread_self(),cp);
 fflush(stdout);
 sleep(2);
 }

