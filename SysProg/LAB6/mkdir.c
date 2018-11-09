#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc, char **argv)
{

  struct stat st ;

  if (stat("testdir", &st) == -1) {
      mkdir("testdir", 0700);

  }else{

      printf("Direcetory exist\n");
  }

  return 0;
}
