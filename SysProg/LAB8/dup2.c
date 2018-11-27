#include<stdlib.h> 
#include<unistd.h> 
#include<stdio.h> 
#include<fcntl.h> 
  
int main() 
{ 

      int fd = open("stdout.txt", O_WRONLY | O_APPEND); 
      if (!fd)
	  perror("Open file");

      // here the newfd is the file descriptor of stdout (i.e. 1) 
     dup2(fd, 1);  
          
     // the printf statements will be written in the file 
     printf("I will be printed in the file stdout.txt\n");       
 
     return 0; 
} 

