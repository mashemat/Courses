#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define NTHREADS	2

static void print_raw(void *addr, size_t size)
{
unsigned char *base = addr;
size_t i;
for (i = 0; i < size; i ++) {
printf("%01x", base[i]);
}

}

void *PrintHello()
{
   printf("Hello World!\n");
   pthread_t self = pthread_self();
   printf("%lu:",getpid() );
   print_raw(&self, sizeof(self) );
   printf("\n");
   pthread_exit(NULL); // exit from thread
}

int main(int argc, char *argv[])
{
   pthread_t threads[NTHREADS]; 
   int rc;
   int t;
   for(t=0;t<NTHREADS;t++){
     printf("Creating threads %d\n", t);
     rc = pthread_create(&threads[t], NULL, PrintHello, NULL);
     if (rc){
       printf("ERROR; return code from pthread_create() is %d\n", rc);
       exit(-1);
       }
     }

   /* Last thing that main() should do */
   pthread_exit(NULL);
}
