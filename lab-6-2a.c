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
};
int sid,p;
char *sm;struct data7 *mydata;
int main(){
key_t k=1008;
sid=shmget(k,sizeof(struct data7), IPC_CREAT | 0666);
sm=shmat(sid,NULL,0);
mydata=(struct data7 *)sm;
printf("Enter your message:");
do{
fgets(mydata->msg,45,stdin);
p=getpid();printf("Pid %d\n",p);
mydata->a=p;
while(p==mydata->a){sleep(1);}
}while(strcmp(mydata->msg,"quit\n")!=0);
shmctl(sid,IPC_RMID,0);
return 0;
}

