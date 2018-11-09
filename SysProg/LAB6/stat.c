#include <unistd.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
 
int main(int argc, char **argv)
{
    if(argc != 2)    
        return 1;
 
    struct stat fileStat;
    if(stat(argv[1],&fileStat) < 0)    
        return 1;
 
    printf("File Size: \t\t%ld bytes\n",fileStat.st_size);

    printf("Owner permissions: \t");
    printf( (fileStat.st_mode & S_IRUSR) ? "r" : "-"); // S_IRGRP, S_IROTH
    printf( (fileStat.st_mode & S_IWUSR) ? "w" : "-");
    printf( (fileStat.st_mode & S_IXUSR) ? "x" : "-");
    printf("\n\n");

    return 0;
}
