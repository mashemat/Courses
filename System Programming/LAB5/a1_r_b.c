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

   if ((fptr = fopen("test.bin","rb")) == NULL){
       perror("Error! opening file");
       exit(1);
   }

   for(n = 0; n < 9; ++n)
   {
      fread(&num, sizeof(struct Num), 1, fptr); 
      printf("n1: %d\tn2(n1*3): %d\tn3(n1*3+1): %d \n", num.n1, num.n2, num.n3);
   }
   fclose(fptr); 
  
   return 0;
}
