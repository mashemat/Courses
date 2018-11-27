
// CPP program to illustrate dup()  
#include<stdio.h> 
#include <unistd.h> 
#include <fcntl.h> 
  
int main() 
{ 
  
    int oldfd = open("dup.txt", O_WRONLY | O_APPEND); 
      
    if(oldfd < 0) 
        printf("Error opening the file\n"); 
      
    int newfd = dup(oldfd); 
          
    write(oldfd,"This will be output to the file named dup.txt\n", 46); 
          
    write(newfd,"This will also be output to the file named dup.txt\n", 51); 
      
    return 0; 
} 
