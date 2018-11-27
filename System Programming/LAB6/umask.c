#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main() {
  int fd;
  mode_t oldmask;

  printf("Your old umask is %d\n",oldmask=umask(S_IRWXG));

  if ((fd = creat("umask.txt", S_IRWXU| S_IRWXO |S_IRWXG)) < 0) //(mode & ~umask)
    perror("creat() error");
  
  return 0;
}
