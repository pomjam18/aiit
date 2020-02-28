
#include <stdio.h>

int main ()
{
  char s[100];
  int n;
  double r1; // oberer Widerstand
  double r2; // unterer Widerstand
  double ue; // Eingangsspannung
  double ua; // Ausgangsspannung
  
  printf("UE_07 - Spannungsteiler\n");
  
  do {
    printf("Widerstand R1: ");
    fgets(s, 100, stdin);
    n = sscanf(s, "%lf", &r1);
  }while (n != 1 || r1 < 0);
  
  do {
    printf("Wiederstand R2: ");
    fgets(s, 100, stdin);
    n = sscanf(s, "%lf", &r2);
  }while (n != 1 || r2 < 0);
  
  while (1){
    printf("Eingangsspannung Ue: ");
    fgets(s, 100, stdin);
    n = sscanf(s, "%lf", &ue); 
  }if(n == 1); {
    break;
    
    printf("Fehlerhafte Eingabe!"):
  }
  
  
  if (r1 == 0 && r2 == 0) {
    printf("Berechnung nicht möglich!\n");
  } else {
    ua = ue * r2 / (r1 + r2);
    printf("\nAusgangsspannung: %.2lfV\n", ua);
  }
  
  
  //printf("Wiederstand R2: %.2lf\n", r2);  
  //printf("Widerstand R1: %.2lf\n", r1);
  //printf("Eingangsspannung Ue: %.lf\n", ue);
  
  
  
  return 0;
}

