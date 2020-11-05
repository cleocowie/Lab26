#include "lab26.h"
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
   // With the functions provided in the Vector ADT,
   //   create a correctly sized vector to read-in all
   //   data from the lab26Data.csv file
   
   char filename[50] = "lab26Data.csv";
   int numLines = getNumLines(filename);
   vector v; 
   vector_create(&v,numLines);
   printf("%d\n",numLines);
   // Utilize your readFile() function from Lab 25
   //   to populate the vector -- you will need to make changes
   //   for this function to perform correctly
   
  readFile(filename,&v,numLines);
  printf("%d is at line 10\n", v.elements[9]);
   // With the functions provided in the Vector ADT,
   //   print the number of vector elements

   int numElements = 0;
   numElements = vector_size(&v);
   printf("Number of elements in the vector is %d\n",numElements);
    
   // With the functions provided in the Vector ADT,
   //   insert a 12 at index 139
    
    vector_insert(&v, 139, 12);


   // With the functions provided in the Vector ADT,
   //   print the number of vector elements

   printf("Number of elements:%d\n",vector_size(&v));
    
    
   // With the functions provided in the Vector ADT,
   //   print the element at index 999

   printf("%d\n",*vector_at(&v,999));
    
   // With the functions provided in the Vector ADT,
   //   erase the element at index 999
    
   vector_erase(&v,999);


   // With the functions provided in the Vector ADT,
   //   print the element at index 999
    
    printf("%d\n",*vector_at(&v,999));

   // With the functions provided in the Vector ADT,
   //   print the number of vector elements

   printf("Number of elements:%d\n",vector_size(&v));
    

    // Using the Vector ADT provided function
    //   vector_push_back to insert the integer 222
   
   vector_push_back(&v,222);

   // With the functions provided in the Vector ADT,
   //   print the number of vector elementss

   printf("Number of elements:%d\n",vector_size(&v));

    

   // With the functions provided in the Vector ADT,
   //   destroy the vector

   vector_destroy(&v);

  system("pause");
  return 0;
}

int getNumLines(char filename[]){
   char c;
   int count = 0;
   FILE* fp= fopen(filename, "r");

   if (fp == NULL) {
      printf("Could not open file %s",filename);
      return 0;
   }

   for (c  = getc(fp); c != EOF; c = getc(fp))
   {
      if (c == '\n'){
         count++;
      }
   }
   
     
   fclose(fp);

   return count;
}

void readFile(char filename[], vector* vectorPtr, int records) {

   FILE*in = fopen(filename,"r");

   if (in == NULL) {
      exit(1);
   }

   int numRead = 0;
   
   while (numRead < records && !feof(in)) {

      fscanf(in,"%d,\n",&vectorPtr->elements[numRead]);

      numRead++;
   }

   fclose(in);

   return;
}