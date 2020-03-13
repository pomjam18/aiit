
#include <stdio.h>

double liefereEingabewert () {
  char s[100];
  int n;
  double rv; //return valeu
  
  do {
      printf("Wert: ");
      fgets(s, 100, stdin);
      n = sscanf(s,"%lf", &rv);
  }while (n != 1);
  
  return rv;
   
}

int main ()
{ 
  printf("UE_08 - Spannungsteiler\n\n");
  
  printf("R1 ");
  double r1 = liefereEingabewert();
  printf("R2 ");
  double r2 = liefereEingabewert();
  printf("Uein ");
  double ue = liefereEingabewert();
  
  // Verarbeitung
  double ua = ue * r2 / (r1 + r2);
  
  //Ausgabe
  printf("Uaus = %.2lfV\n",ua);

  return 0;
}

