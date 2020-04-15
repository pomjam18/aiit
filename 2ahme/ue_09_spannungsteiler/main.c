

#include <stdio.h>
#include <stdlib.h>

double liefereEingabewert (char text[], int nurPositiveWerte) {
  char s[100];
  int n;
  double rv; //return valeu
  
  do {
      printf("%s", text);
      fgets(s, 100, stdin);
      n = sscanf(s, "%lf", &rv);
  }while (n != 1 || nurPositiveWerte && rv < 0);
  
  return rv;
   
}

int main ()
{
printf("UE_09 - Spannungsteiler\n-----------------------\n");
  
  printf("\n");
  double r1 = liefereEingabewert("R1: ", 1);
  
  double r2 = liefereEingabewert("R2: ", 1);
  
  double ue = liefereEingabewert("Uein: ", 0);
 
  // Verarbeitung
  double ua = ue * r2 / (r1 + r2);
  
  //Ausgabe
  printf("Uaus = %.2lfV\n",ua);
  
  
  
  
  return 0;
}

