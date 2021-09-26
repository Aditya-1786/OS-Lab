#include <stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>
void mysignal(int signum)// signal handler
{
 puts("I'll not terminate");
 signal(signum,mysignal);
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
