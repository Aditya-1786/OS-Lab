#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<string.h>
#include<stdbool.h>
#include<time.h>
struct data {
bool flag[2];
int turn;
};
int sid;
char *sm;
struct data *mydata;
int main(int argc, char *argv[]){
srand(time(NULL));
key_t k=1008;
int i;
sid=shmget(k,sizeof(struct data), IPC_CREAT | 0666);
sm=shmat(sid,NULL,0);
mydata=(struct data *)sm;
mydata->turn=1;
mydata->flag[0]=0;
mydata->flag[1]=0;
for(i=0;i<10;i++){
printf("\nBefore turn %d, s0= %d s1= %d %s in CR\n",mydata->turn,mydata->flag[0],mydata->flag[1],argv[0]);
 //check
mydata->flag[1]=1;
mydata->turn=1;
while(mydata->flag[0]&&mydata->turn==1);
printf("\n\t\tIn CS turn=%d, s0= %d s1= %d, %s in CR\n",mydata->turn,mydata->flag[0],mydata->flag[1],argv[0]);
sleep(rand()%5);
//release
sleep(2);
mydata->flag[1]=0;
}
return 0;
}

