#include <stdio.h>
#include <stdlib.h>

struct Num
{
   int n1, n2, n3;
};

int main()
{
   int n;
   struct Num num;
   FILE *fptr;

   if ((fptr = fopen("test.bin","wb")) == NULL){
       perror("Error! opening file");
       exit(1);
   }

   for(n = 10000; n < 10009; ++n)
   {
      num.n1 = n;
      num.n2 = 3*n;
      num.n3 = 3*n + 1;
      fwrite(&num, sizeof(struct Num), 1, fptr); 
   }
   fclose(fptr); 
  
   return 0;
}
