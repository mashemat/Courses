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
       printf("Error! opening file");

       // Program exits if the file pointer returns NULL.
       exit(1);
   }
   
   // Moves the cursor to the end of the file
   fseek(fptr, -sizeof(struct Num), SEEK_END);

   for(n = 0; n < 9; ++n)
   {
      fread(&num, sizeof(struct Num), 1, fptr); 
      printf("n1: %d\tn2: %d\tn3: %d\n", num.n1, num.n2, num.n3);
      fseek(fptr, -2*sizeof(struct Num), SEEK_CUR);
   }
   fclose(fptr); 
  
   return 0;
}
