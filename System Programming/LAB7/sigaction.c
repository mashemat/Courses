#include<stdio.h>
#include<signal.h>
#include<unistd.h>
#include<wait.h> 
#include <sys/types.h>
#include <stdlib.h>


void sighandlerchld(int sig){

   printf("Hey there! signal received %d\n", sig);
   sleep(5);

}


int main(){

 
   struct sigaction sigchld;

   if ((sigemptyset(&sigchld.sa_mask) == -1)){  // mask has sigset_t data type
     perror("Failed to initialize the signal mask");
     return 1;
   }

   sigchld.sa_flags = 0;
   sigchld.sa_handler = sighandlerchld;
   sigaction(SIGCHLD, &sigchld, NULL);

   //raise(SIGCHLD);
    if (fork() == 0){//Child
	sleep(2);
        exit(0); 
    }
    else // parent
       wait(NULL);
   
 
   return 0;
}
