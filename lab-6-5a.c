#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<string.h>
#include<time.h>
int main(int argc, char *argv[]){
int shmid;
int key,i;
char *shm,*turn;
key = 0x1008;
 srand ( time(NULL));
 if ((shmid = shmget(key, sizeof(char), IPC_CREAT | 0666)) < 0)
 {printf("shared get memory ERROR\n");exit(-1);}
 if ((shm = shmat(shmid, NULL, 0)) == (char *) -1)// attached to memory address provided by system
 {printf("shared attach memory ERROR\n");exit(-1);}
turn=shm;
*turn=0;
for(i=0;i<5;i++)
{
printf("\nBefore turn %d, %s in CR\n",*turn,argv[0]);
 //check
while(*turn!=0);
printf("\n\t\tIn CS turn= %d ,%s in CR\n",*turn,argv[0]);
 sleep(rand()%10);
//release
 sleep(2);
 *turn=1; //now P2 may enter
 }
return 0;
}

