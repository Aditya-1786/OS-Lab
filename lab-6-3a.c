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
int shmid1,shmid2,shmid3;
int key1,key2,key3,i;
char *shm1,*shm2,*shm3, *turn,*s0,*s1;
key1 = 0x10081;
 srand ( time(NULL));
 if ((shmid1 = shmget(key1, sizeof(char), IPC_CREAT | 0666)) < 0)
 {printf("shared 1 get memory ERROR\n");exit(-1);}
 if ((shm1 = shmat(shmid1, NULL, 0)) == (char *) -1)
// attached to memory addressprovided by system
 {printf("shared 1 attach memory ERROR\n");exit(-1);}
key2 = 0x10082;
 srand ( time(NULL));
 if ((shmid2 = shmget(key2, sizeof(char), IPC_CREAT | 0666)) < 0)
 {printf("shared 2 get memory ERROR\n");exit(-1);}
 if ((shm2 = shmat(shmid2, NULL, 0)) == (char *) -1)// attached to memory address provided by system
 {printf("shared 2 attach memory ERROR\n");exit(-1);}
key3 = 0x10083;
 srand ( time(NULL));
 if ((shmid3 = shmget(key3, sizeof(char), IPC_CREAT | 0666)) < 0)
 {printf("shared 3 get memory ERROR\n");exit(-1);}
 if ((shm3 = shmat(shmid3, NULL, 0)) == (char *) -1)// attached to memory address provided by system
 {printf("shared 3 attach memory ERROR\n");exit(-1);}
 turn=shm1;
 s0=shm2;
 s1=shm3;
 *turn=1;
 *s0=1;
 *s1=1;
 for(i=0;i<10;i++)
 {printf("\nBefore turn %d, s0= %d s1= %d %s in CR\n",*turn,*s0,*s1,argv[0]);
 //check
*s0=0; //P1 want to enter
 while(*s1==0) // P2 wants and in CR
 {if(*turn==2) // P2 turn
 { *s0=1; //P1 give up chance
 while(*turn==2);// wait until turn change to 1
 *s0=0;
 } }
 ;//wait for turn to become 1
 printf("\n\t\tIn CS turn= %d, s0= %d s1= %d ,%s in CR\n",*turn,*s0,*s1,argv[0]);
 sleep(rand()%5);//sleep for random duration 0 to 4 sec
//release
 sleep(2);
 *turn=2; //now P2 may enter
 *s0=1;// P1 outside CR
 printf("\nAfter turn %d, s0 %d s1 %d %s in CR\n",*turn,*s0,*s1,argv[0]);
 }
return 0;
}


