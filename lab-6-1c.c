#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include <sys/stat.h>
#include<fcntl.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<string.h>
#include<ctype.h>

int main(int argc, char*argv[])
{
	char* npi[] = {"/tmp/1008-0", "/tmp/1008-1"};
	char buf[256];
	int x = 1, y = 2;
	int a = mkfifo(npi[0], 0777), b = mkfifo(npi[1], 0777);

	if (argv[1][0] == '1') {x = 0; y = 1;}
	else {x = 1; y = 0;}
	int fpl1 = open(npi[x], O_RDWR);
	int fpl2 = open(npi[y], O_RDWR);
	if (fork())
	{
		do {
			fgets(buf, 40, stdin);
			write(fpl1, buf, sizeof(buf));

		}
		while (strcmp(buf, "quit\n") != 0);
		write(fpl2, buf, sizeof(buf));
	}
	else
	{
		read(fpl2, buf, sizeof(buf));
		while (strcmp(buf, "quit\n") != 0)
		{
			fputs(buf, stdout);
			read(fpl2, buf, sizeof(buf));
		}
		printf("Connection Broke!\n" );
	}
	unlink(npi[x]);
	unlink(npi[y]);
	return 0;

}
