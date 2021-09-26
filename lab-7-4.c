#include <stdio.h>
#include<stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
void *decker1();
void *decker2();
int turn=1,s0=0,s1=0;
int main(){
 pthread_t th1,th2; /* two threads */
// Two different functions are assigned to different -
 pthread_create(&th1, NULL, decker1, (void*) NULL); // process P0
 pthread_create(&th2, NULL, decker2, (void*) NULL); // process P1
 pthread_join(th1, NULL);
 pthread_join(th2, NULL);
}
// defination of function
void *decker1()
{
int n;
for(n=0;n<10;n++)
 {
printf("\nBefore inside. count %d turn %d, s0= %d s1= %d %lu\n",n,turn,s0,s1,pthread_self());
 //check
 s0=1; //P1 want to enter
 while(s1==1) // P2 wants and in CR
 {if(turn==2) // P2 turn
 { s0=0; //P1 give up chance
 while(turn==2);// wait until turn change to 1
 s0=1;
 } }
 printf("\n\t\tIn CS. count %d turn= %d, s0= %d s1= %d ,%lu\n",n,turn,s0,s1,pthread_self());
// leave the CR
 usleep(rand()%2000000);
 turn=2; //now P2 may enter
 printf("\nAfter outside. count %d turn %d, s0 %d s1 %d %lu\n",n,turn,s0,s1,pthread_self());
 s0=0;// P1 outside CR
 }
}
void *decker2()
{
int n;
for(n=0;n<10;n++)
 {
printf("\nBefore inside. count %d turn %d, s0= %d s1= %d %lu\n",n,turn,s0,s1,pthread_self());
 //check
 s1=1; //P2 want to enter
 while(s0==1) // P1 wants and in CR
 {if(turn==1) // P1 turn
 { s1=0; //P2 give up chance
 while(turn==1);// wait until turn change to 2
 s1=1;
 } }
 printf("\n\t\tIn CS. count %d turn= %d, s0= %d s1= %d ,%lu\n",n,turn,s0,s1,pthread_self());
// leave the CR
 usleep(rand()%2000000);
 turn=1; //now P2 may enter
 printf("\nAfter outside. count %d turn %d, s0 %d s1 %d %lu\n",n,turn,s0,s1,pthread_self());
 s1=0;// P2 outside CR
 }
}
