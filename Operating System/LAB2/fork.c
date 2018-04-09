#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
// char * cmd[] = { "ls", "-l", (char *)0 };
 char * cmd[] = { "ex", (char *)0 };
	pid_t pid;
		pid = fork();
		if (pid == 0) {
//                 execv("ex",cmd); 
//                 execv("/bin/ls",cmd); 
	    	  exit(0);
		}
       else {
                sleep(12);
}
       return 0;
}
