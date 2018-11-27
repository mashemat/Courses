#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

#define READ 0
#define WRITE 1

struct pipe_data{
char * name;
int id;
};

char *cmsg = "This is my first msg to pipe"; //28
char *pmsg;

int main () {

  int fd[2], nread;

  struct pipe_data receive[3];
  struct pipe_data send[3] = {"masoud", 30, "mansour", 20, "alberto", 10 };
  memset(&receive, 0, sizeof(struct pipe_data)); 

  pipe (fd); 
  
  if (fork()==0) {
    close (fd[READ]); 
    write (fd[WRITE], &send[0], sizeof(struct pipe_data)); 
    write (fd[WRITE], cmsg, strlen(cmsg) +1); 
    write (fd[WRITE], &send[1], sizeof(struct pipe_data)); 
    write (fd[WRITE], &send[2], sizeof(struct pipe_data)); 
    close (fd[WRITE]); 
    printf("Child:  Wrote to pipe!\n");

  } else {

    close (fd[WRITE]); 
    nread = read (fd[READ], &receive[0], sizeof(struct pipe_data));
    pmsg=malloc(29);
    nread = read ( fd[READ], pmsg, 28);
    nread = read (fd[READ], &receive[1], sizeof(struct pipe_data));
    nread = read (fd[READ], &receive[2], sizeof(struct pipe_data));
    printf ("Parent: Read from pipe: %s:%d\n", receive[0].name,receive[0].id);
    printf ("Parent: Read from pipe: %s:%d\n", receive[1].name,receive[1].id);
    printf ("Parent: Read from pipe: %s:%d\n", receive[2].name,receive[2].id);
    printf ("Parent: Read from pipe: %s\n", pmsg);
    close (fd[READ]); 
  } 
  return 0;
}
