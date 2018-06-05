#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

int counter = 0;

void *compute1()
{
       int i=0;
       for(i=0;i<1000;i++)
	counter++;

}

void *compute2()
{
        int i=0;
        for(i=0;i<1000;i++)
	counter--;
}
int main() 
{
	pthread_t thread1, thread2;

	pthread_create(&thread1, NULL, compute1, NULL);
	pthread_create(&thread2, NULL, compute2, NULL);

   	pthread_join( thread1, NULL);
   	pthread_join( thread2, NULL);
	printf("Counter value: %d\n", counter);

	exit(0);
}

