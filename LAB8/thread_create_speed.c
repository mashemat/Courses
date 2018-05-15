#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>


void *PrintHello()
{
   pthread_exit(NULL); // exit from thread
}

int main(int argc, char *argv[])
{
   pthread_t threads; 
   pthread_create(&threads, NULL, PrintHello, NULL);
   pthread_exit(NULL);
}
