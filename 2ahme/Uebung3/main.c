#include <stdio.h>

int main()
{
  char s[100];
  double wiederstand;
  double spannung;
  double stromstaerke;
  
  printf(" Stomstärke Rechner \n");
  printf(" ------------------ \n\n");
  
  printf(" Spannung:");
  fgets(s, 100, stdin);
  sscanf(s, "%lf", &spannung);
  
  printf(" Wiederstand: ");
  fgets(s, 100, stdin);
  sscanf(s, "%lf", &wiederstand);
  
  stromstaerke = spannung/wiederstand;
  
  printf(" \n Stromstärke = %lfA",stromstaerke);
  
  return 0;
  
  
}