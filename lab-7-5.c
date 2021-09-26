#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
int turn =0,s[2]={0,0};//global to threads
void *peter(void* th); // function to be executed concurrently
int main()
{
 pthread_t mth[2]; /* two threads */
 int thid[2]={0,1}; //thread id
 int i;
// create two theads with different parameter
for(i=0;i<2;i++)
 pthread_create(&mth[i], NULL, peter, (void *) &thid[i]); // pass thread number asinteger
 // wait for termination of all threads
for(i=0;i<2;i++)
 pthread_join(mth[i], NULL);
return 0;
}
// defination of function
void *peter(void* th)
{
 int i = *(int*)th;
 int otherpr,otherturn,n;
 // ith process want to enter
 otherpr =1-i ; // other process id
 otherturn =1-i; // turn of other process
 for(n=0;n<10;n++)
 {
 printf("\nBefore inside CS. count %d id- %d turn %d, s0= %d s1= %d %lu\n",n,i,turn,s[0],s[1],pthread_self());
 //check before enter
 s[i]=1; //P1 want to enter
 turn=otherturn;//i iveup
 while( s[otherpr] && turn==otherturn); // P2 wants and in CR
 //wait for turn to become 1
 printf("\n\t\tIn CS. count %d turn= %d, s0= %d s1= %d ,%lu\n",n,turn,s[0],s[1],pthread_self());
 usleep(rand()%400000*(i+1));
// leave the CR
 //now P2 may enter
 printf("\nAfter outside. count %d turn %d, s0 %d s1 %d %lu\n",n,turn,s[0],s[1],pthread_self());
 s[i]=0;// P1 outside CR
 // sched_yield(); // you skip this statement
 }
}
