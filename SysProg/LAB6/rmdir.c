#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc, char **argv)
{

  struct stat st ;
  if (stat("testdir", &st) != -1) {
      rmdir("testdir");
  }
  else{
      printf("Directory does not exist\n");
  }

  return 0;
}
