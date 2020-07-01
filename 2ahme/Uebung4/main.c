#include <stdio.h>
#include <stdlib.h>

int main () {

int v [10][10];    
    
 printf("Übung 4: 1mal1\n");
 
 for (int i = 1; i < 10; i++) {
     for (int j = 0; j < 10; j++) {
      v[i][j] = j * i;   
     }
 }
   
 printf("Dezimalsystem:\n");
 printf("    |");
 for (int i = 1; i < 10; i++) {
     printf("%4d |", i);
 }
      printf("\n");

 for (int i = 1; i < 65; i++) {
     printf("-");
 }
       printf("\n");

      
 for (int i = 1; i < 10; i++) {
     printf("%3d |", i);
     for (int j = 1; j <= 10; j++) {
         printf("%4d |", v[i][j]);
     }
 }   
return 0;
}

