#include <pthread.h>
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 
 pthread_attr_t attr;
 
 void *dowork(void *threadid)
 {
    pthread_exit(NULL);
 }
 
 int main(int argc, char *argv[])
 {
    pthread_t threads;
    size_t stacksize;
    int rc;
    long t;
 
    pthread_attr_init(&attr);
    pthread_attr_getguardsize (&attr, &stacksize);
    printf("Default stack size = %li\n", stacksize);
    stacksize +=10;

    pthread_attr_setguardsize (&attr, stacksize);

    printf("New set  thread = %li\n",stacksize);

    printf("Creating threads with stack size = %li bytes\n",stacksize);

    rc = pthread_create(&threads, &attr, dowork, (void *)t);
    if (rc){
          printf("ERROR; return code from pthread_create() is %s\n", strerror(rc));
          exit(-1);
    }
    pthread_attr_destroy(&attr);
    printf("Created %ld threads. \n", t);
    pthread_exit(NULL);
 }
