#include <stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>
void mysignal(int signum)// signal handler
{
 printf("Alarm captured going to exit now");
 exit(0);
}
int main()
{
 signal(SIGALRM, mysignal);
 alarm(15);
 pause();
return 0;
}

