#include<stdio.h>
#include<signal.h>
#include<unistd.h>

struct sigaction siguser, sigint;

void sighandleruser(int sig){


   printf("Hey there! USER start to sleep signal %d\n", sig);
   fflush(stdout);

   sleep(10);

   
   printf("Hey there! USER end to sleep signal %d\n", sig);
   fflush(stdout);


}

void sighandlerint(int sig){
   printf("Hey there! Just got SIGINT signal %d\n", sig);
   fflush(stdout);
   sleep(10);
}

int main(){

 
//   sigemptyset(&siguser.sa_mask);
   if ((sigemptyset(&siguser.sa_mask) == -1) || (sigaddset(&siguser.sa_mask, SIGINT) == -1)){
     perror("Failed to initialize the signal mask");
     return 1;
   }

   siguser.sa_flags = 0;
   siguser.sa_handler = sighandleruser;


   sigemptyset(&sigint.sa_mask);
   sigint.sa_flags = 0;
   sigint.sa_handler = sighandlerint;

   sigaction(SIGUSR1, &siguser, NULL);
   sigaction(SIGINT, &sigint, NULL);

//   raise(SIGUSR1);
   sleep(50);
   return 0;
}
