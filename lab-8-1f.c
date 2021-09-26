#include <stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>
void mysignal(int signum)// signal handler
{
 puts("You have pressed ctrl-z");
 signal(signum,SIG_IGN);
}
int main()
{
 signal(SIGTSTP, mysignal);
while(1)
 {
 printf("Program id %d.\n",getpid());
 sleep(1);
 }
return 0;
}
