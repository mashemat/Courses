#include <stdlib.h> 
#include <sys/types.h> 
#include <unistd.h> 
#include <signal.h> 
#include <sys/wait.h>

int main() 
{ 

    pid_t child_pid = fork(); 
  
    // Parent process  
    if (child_pid != 0) 
    {
    /*Solutions*/	    
    //    wait(NULL);
    	signal(SIGCHLD,SIG_IGN); 
    //	Anyway init handle when parent dies
        sleep(60);
    }
    // Child process 
    else        
        exit(0); 
  
    return 0; 
} 
