#include<stdio.h> 
#include<stdlib.h> 
#include<signal.h> 
#include<wait.h> 
#include <sys/types.h>
#include <unistd.h>

/* the disposition of a particular signal is the same for all threads Each thread in a process has an independent signal mask

A child created via fork() inherits a copy of its parent's signal dispositions

During an execve(), the dispositions of handled signals are reset to the default

pause() calls suspend execution of the calling process

sigwait() for synchronous communication

Between the time when it is generated and when it is delivered a signal is said to be pending.

Order of delivery of signal is not guaranteed to be the same as the sending order.

Blocking a signal is not similar to Ignoring a signal

*/

void handler(int sig)  
{ 
    printf("Child Terminated %d\n",sig); 
    sleep(10);
} 
int main() 
{ 

    pid_t pid; 
    signal(SIGCHLD, handler); 
    if (fork() == 0){//Child
	sleep(20);
        exit(0); 
    }
    else // parent
        wait(NULL);
        return 0;
} 
