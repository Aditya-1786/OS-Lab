#include <stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>
void mysignal(int signum)// signal handler
{
 printf("next ^c programme will be terminated");
 signal(signum,SIG_DFL);
}
int main()
{
 signal(SIGINT, mysignal);//SIGINT 2
while(1)
 {
 printf("Program id %d.\n",getpid());
 sleep(1);
 }
return 0;
}
