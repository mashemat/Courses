//#define _POSIX_SOURCE
#include <fcntl.h>
#include <unistd.h>
//#undef _POSIX_SOURCE
#include <stdio.h>

int main() {
  int ret, fd;
  char buf[1024];

  if ((fd = open("test.txt", O_RDONLY)) < 0)
    perror("open() error");
  else {
    while ((ret = read(fd, buf, sizeof(buf)-1)) > 0) {
      buf[ret] = 0x00;
      printf("read:%s", buf);
    }
    close(fd);
  }
 return 0;
}
