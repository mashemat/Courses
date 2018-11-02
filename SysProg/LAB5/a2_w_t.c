#include <unistd.h>
#include <fcntl.h>

int main(void)
{
    int fd = open("test.txt", O_WRONLY);
 
    if (fd < 0) {
          write(1,"open error",10);
	  return -1;
    }
 
    if (write(fd, "2", 1) != 1) {
          write(1,"write error",11);
	  return -1;
    }
    return 0;
}
