#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  pid_t pid;
  pid = fork();
  if (pid < 0) {
    perror("fork failed");
    exit(1);
  }
  if (pid == 0) {
       sleep(1);
       printf("Child is going to terminate\n");
       exit(3);
  } else {
       int stat_val;
//       waitpid(pid, &stat_val, 0);
       waitpid(pid, &stat_val, WNOWAIT);
       sleep(3);
       waitpid(pid, &stat_val, 0);
     if (WIFEXITED(stat_val))
       printf("Child exited with code %d\n", WEXITSTATUS(stat_val));
  }
  return 0;
}
