#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdio.h>

int main(int argc, char **argv)
{
  FILE *stream;
  struct stat info;

    stat(argv[1], &info);
    printf("original owner was %d and group was %d\n", info.st_uid,
           info.st_gid);
    if (chown(argv[1], 1001, 1001) != 0)
      perror("chown() error");
    else {
      stat(argv[1], &info);
      printf("after chown(), owner is %d and group is %d\n",
             info.st_uid, info.st_gid);
    }
}
