#include <unistd.h>
#include <stdio.h>


int main(int argc, char **argv)
{

  char *path1 = "file1";
  char *path2 = "link_to_file1";

#ifdef LINK

  if(link (path1, path2)<0){
      printf("Error\n");
      return 1;
  }

#else

  unlink(path2);

#endif

  return 0;
}



