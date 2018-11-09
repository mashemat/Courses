#include <dirent.h>
#include <stdio.h>

int main(int argc, char **argv){

 DIR *dp;
 struct dirent *inf;

 dp = opendir ("/home");

 while ((inf=readdir(dp))!=0)
   printf ("%s\n", inf->d_name);

 closedir (dp);

 return 0;

}
