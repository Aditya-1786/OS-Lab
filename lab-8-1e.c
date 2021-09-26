#include <stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>
void mysignal(int signum)// signal handler
{
 printf("You have pressed ctrl-\\\n");
 signal(signum,SIG_IGN);
}
int main()
{
 signal(SIGQUIT, mysignal);//SIGINT 2
while(1)
 {
 printf("Program id %d.\n",getpid());
 sleep(1);
 }
return 0;
}
