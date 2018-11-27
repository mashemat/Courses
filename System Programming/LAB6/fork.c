#define _POSIX_SOURCE
#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main() {
  pid_t pid;
  int status;

  if ((pid = fork()) < 0)
    perror("fork() error");//Error

  else if (pid == 0) { // Child
    printf("Child's pid is %d and my parent's is %d\n",
           (int) getpid(), (int) getppid());
    exit(4);
  }
  else {  // Parent
    printf("Parent's pid is %d and my child's is %d\n",
            getpid(),  pid);
    if (wait(&status) == -1) // Process will be blocked here
      perror("wait() error");
    else if (WIFEXITED(status)) // child exited normally
           printf("The child exited with status of %d\n",
                  WEXITSTATUS(status)); // low-order 8 bits of the status
         else
           printf("The child did not exit successfully");
 }
}
