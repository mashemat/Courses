#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

#define READ 0
#define WRITE 1

char *cmsg = "This is my first msg in pipe"; // 28
char *pmsg;

int main () {

  int fd[2], nread;
  pipe (fd); 
  if ( fork() == 0 ) {
    close (fd[READ]); 
    write (fd[WRITE], cmsg, strlen(cmsg) +1); /* include NULL*/
    printf("Child: Wrote '%s' to pipe!\n", cmsg);
    close(fd[WRITE]); 
  } else {
    close (fd[WRITE]); 
    pmsg=malloc(28);
    nread = read (fd[READ], pmsg, 100);
    printf("Parent: Read '%s' from pipe!\n", pmsg);
    close (fd[READ]); 
  } 
  return 0;
}
