#include <stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>
int main(int argc ,char *argv[])
{
int pid=atoi(argv[1]);
kill(pid,SIGABRT);
return 0;
}
