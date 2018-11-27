#include<stdio.h> 
#include <unistd.h> 
#include <fcntl.h> 
  
int main() 
{ 


    int oldfd = open("dup.txt", O_WRONLY | O_APPEND); 
      
    if(oldfd < 0) 
        printf("Error opening the file\n"); 
      
    close(1);	
    int newfd = dup(oldfd); 
    printf("%d",newfd);      
    write(oldfd,"This will be output to the file named dup.txt\n", 46); 
    char out[57];
    sprintf(out, "This will also be output (%d) to the file named dup.txt\n", newfd ); 
    write(newfd,out, 57); 
      
    return 0; 
} 
