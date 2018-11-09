#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void){

    int val;
    printf("This process is %d\n", getpid());
    printf("The real user ID is %d\n", getuid());
    printf("Real group ID: %d\n", getgid());
    printf("The parent process is %d\n", getppid());
    return 0;

}
