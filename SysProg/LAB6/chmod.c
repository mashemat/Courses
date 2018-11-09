#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>

int main(int argc, char **argv)
{

  struct stat fileStat;

  chmod(argv[1], S_IRWXU|S_IRWXG|S_IROTH|S_IWOTH);

  if(stat(argv[1],&fileStat) < 0)
        return 1;

  printf("Owner permissions: \t");
  printf( (fileStat.st_mode & S_IRUSR) ? "r" : "-"); 
  printf( (fileStat.st_mode & S_IWUSR) ? "w" : "-");
  printf( (fileStat.st_mode & S_IXUSR) ? "x" : "-");

  printf( (fileStat.st_mode & S_IRGRP) ? "r" : "-"); 
  printf( (fileStat.st_mode & S_IWGRP) ? "w" : "-");
  printf( (fileStat.st_mode & S_IXGRP) ? "x" : "-");

  printf( (fileStat.st_mode & S_IROTH) ? "r" : "-"); 
  printf( (fileStat.st_mode & S_IWOTH) ? "w" : "-");
  printf( (fileStat.st_mode & S_IXOTH) ? "x" : "-");

  printf("\n\n");

  return 0;

}
