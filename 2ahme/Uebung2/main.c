#include <stdio.h>
        
int main ()
{
  char s [100];
  double einkommen;
  double steuer;
  
  printf(" Einkommenssteuerrechner \n");
  printf(" ----------------------- \n\n");
  
  printf(" Einkommen: ");
  fgets(s, 100, stdin);
  sscanf(s, "%lf", &einkommen);
  
  if (einkommen<= 0) {
    printf(" Fehlerhafte Eingabe ");
    return 1;
  } if (einkommen<11000) {
    steuer = einkommen*0;
  } else if (einkommen<18000) {
    steuer = einkommen*0.25;
  } else if (einkommen<31000) {
    steuer = einkommen*0.35;
  } else if (einkommen<60000) {
    steuer = einkommen*0.42;
  } else if (einkommen<90000) {
    steuer = einkommen*0.48;
  } else if (einkommen<1000000) {
    steuer = einkommen*0.5;
  } else {
    steuer = einkommen*0.55;
  }
  printf(" Steuer = %.2f\n", steuer);
  
  return 0;
}