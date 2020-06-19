#include <stdio.h>
 
 int main () {
   
     int v[17][17];   
 
     printf("Ue15: Kleines 1mal1\n");
     
   
     for (int i = 0; i <= 16; i++) {
         for (int j = 0; j <= 16; j++) {
             v[i][j] = i * j;
         }
     }
     
     printf("\nDezimalsystem:\n\n");
     printf("    |");
     for (int i = 1; i <= 10; i++) {
         printf("%4d |", i);
     }
     printf("\n");
     for (int i = 0; i < 65; i++) {
         printf("-");
     }
     printf("\n");
     
     for (int i = 1; i <= 10; i++) {
         printf("%3d |", i);
         for (int j = 1; j <= 10; j++) {
             printf("%4d |", v[i][j]);
         }
         printf("\n");
     }
     
     printf("\n\nOktalsystem:\n\n");
     printf("    |");
     for (int i = 1; i <= 8; i++) {
         printf("%4o |", (unsigned)i);
     }
     printf("\n");
     for (int i = 0; i < 53; i++) {
         printf("-");
     }
     printf("\n");
     
     for (int i = 1; i <= 8; i++) {
         printf("%3o |", (unsigned)i);
         for (int j = 1; j <= 8; j++) {
             printf("%4o |", (unsigned)v[i][j]);
         }
         printf("\n");
     }
     
     printf("\n\nHex-System:\n\n");
     printf("    |");
     for (int i = 1; i <= 16; i++) {
         printf("%4x |", (unsigned)i);
     }
     printf("\n");
     for (int i = 0; i < 101; i++) {
         printf("-");
     }
     printf("\n");
     
     for (int i = 1; i <= 16; i++) {
         printf("%3x |", (unsigned)i);
         for (int j = 1; j <= 16; j++) {
             printf("%4x |", (unsigned)v[i][j]);
         }
         printf("\n");
     }
     
     return 0;
 }