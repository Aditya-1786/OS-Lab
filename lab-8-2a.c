#include <stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>
void mysignal(int signum)// signal handler
{
 printf("Divide by Zero");
 signal(signum,SIG_IGN);
}
int main()
{
 signal(SIGFPE, mysignal);
 int a=0,b=5,c;
 while(1){
 c=b/a;
 sleep(1);
 }
return 0;
}

