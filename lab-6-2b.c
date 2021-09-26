#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<string.h>
struct data7 {
char msg[50];
int a;
};int sid,p;
char *sm;
struct data7 *mydata;
int main(){
key_t k=1008;
sid=shmget(k,sizeof(struct data7), IPC_CREAT | 0666);
sm=shmat(sid,NULL,0);
mydata=(struct data7 *)sm;
while(strcmp(mydata->msg,"quit\n")!=0){
printf("%s Other process id is %d\n",mydata->msg,mydata->a);
mydata->a=getpid();
while(getpid()==mydata->a){sleep(1);}
}
mydata->a=getpid();
shmdt(mydata);
return 0;
}

