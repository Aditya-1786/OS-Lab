#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>


int main()
{
        pid_t pid=fork();
       int i;

       if(pid==0)
           {  fork();
              printf ( "child id is %u parent id is %u \n", getpid (),getppid());

           }
      if(pid!=0)
            {
              for(i=0;i<2;i++)
                        {  fork();}

             printf ( "child id is %u parent id is %u \n", getpid (),getppid());
           }

      for(i=0;i<3;i++)
         wait(NULL);


      return 0; // End child process
}
