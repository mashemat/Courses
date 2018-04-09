#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

int main_work=1;

void ALRMhandler (int sig)
{

  main_work = 0;
}

int main( int argc, char** argv ){

   int testtime=1;
   if (argc > 1)
      testtime = atoi(argv[1]);
   else
      printf("It works with default \n");

   int i;
   signal (SIGALRM, ALRMhandler);
   alarm (testtime);

   for ( i=0 ; main_work ; i++)
     i++;
  
   printf("This is the number of execution:%d ", i );

}
