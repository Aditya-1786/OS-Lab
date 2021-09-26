#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<string.h>
int main(){
char NPIPE[]="/tmp/1008";
char buf[256];
int fpl=open(NPIPE,O_RDONLY);
read(fpl,buf,sizeof(buf));
while(strcmp(buf,"quit\n")!=0){
fputs(buf,stdout);
read(fpl,buf,sizeof(buf));
}
unlink(NPIPE);
return 0;
}
