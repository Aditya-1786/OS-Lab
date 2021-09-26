#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
int len, thn;
int **arr;
long sum;
void *adder(void *arg)
{
 int tid =*(int*) arg;
 int i, j, k;
 int start = tid * len/thn;
 int end = (tid+1) * (len/thn) - 1;
 
for(i = start; i <= end; i++) {
	 for(j = 0; j < len; j++) {
 		for(k = 0; k < len; k++) {
		 sum += arr[i][k];
 		}
	 }
 }
 printf("\n sum %lu id %lu ",sum,pthread_self());
}
int main(int argc, char* argv[])
{
 pthread_t* thrid;
 int i, j;
 len = atoi(argv[1]);
 thn = atoi(argv[2]);
 arr = (int**)malloc(len * sizeof(int *)); // memory for array

 for(i = 0; i < len; i++)
 arr[i] = malloc(len * sizeof(int));

 for(i = 0; i < len; i++)
	 for(j = 0; j < len; j++) { arr[i][j] = rand()%10; }//initialize array
 		thrid = (pthread_t*)malloc(thn * sizeof(pthread_t));// array to hold threadid

 for(i = 0; i < thn; i++)
	 pthread_create(&thrid[i], NULL, adder, (void *)&i);

 for(i = 0; i < thn; i++) pthread_join(thrid[i], NULL);
	 printf("\n sum %lu id %lu ",sum,pthread_self());
 
for(i = 0; i < len; i++)
 free((void *)arr[i]);
 free((void *)arr);
 free(thrid);
 return 0;
}

