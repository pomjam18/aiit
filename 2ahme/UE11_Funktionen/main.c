
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int getInputIntegerValue (char text[]) {
  char s[100];
  int n;  
  int rv;

  do{
    printf("%s: ", text);
    fgets(s, 100, stdin);
    n = sscanf(s, "%d", &rv);
  }while (n != 1);
  
  return rv;
}


double getInputDoubleValue (char text[]) {
  char s[100];
  int n;
  double rv;
   
  do{
  printf("%s: ", text);
    fgets(s, 100, stdin);
    n = sscanf(s, "%lf", &rv);
  }while (n != 1);
  
  return rv;     
  }


int getSelectMenu () {
   double rv;
    
  do{
    printf("-----------------------\n1 ... Würfel\n2 ... Quader\n3 ... Kugel\n4 ... Programm beenden");
    
    rv = getInputIntegerValue("Auswahl (1-4):")
            
  }while (rv < 1 || rv >4);
  
return rv;
}
  

 double calcCube () {
   double l;
   
  printf("Wuerfel:\n");  
   
 do{
   double l = getInputDoubleValue("Länge: ");
   
 }while (l < 0);
 
  double volumen = l * l * l;
  double oberflaeche = l * l *6; 


  printf("Volumen:%2.lf\n", volumen);
  printf("Oberfläche: %2.fl\n", oberflaeche);
  
  return 0;
 }
 
   
 double calcCuboid () {
   double l;
   double h;
   double b;
   
 printf("Quader: \n");
 
 do{
  double l = getInputDoubleValue("Länge: ");
 }while (l < 0);
 do{
  double b = getInputDoubleValue("Breite: ");
 }while (b < 0);
 do{
  double h = getInputDoubleValue("Höhe: ");
 }while (h < 0);
  
   
   double volumen = l * b * h;
   double oberflaeche = 2 * l * b + 2 * l * h + 2 * b * h;
   
   printf("Volumen: %.2lf", volumen);
   printf("Oberfläche: %.2lf", oberflaeche);
   
   return 0;
 }
 
 
 double calcSphere(){
   double d;
   
 printf("Kugel:\n");
 
 do{
    d = getInputDoubleValue("Durchmesser: ");
 }while (d < 0);
 
 double r = d / 2;
 double volumen = (4 / 3) * M_PI * r * r * r;
 double oberflaeche = 4 * M_PI * r * r;
 
 printf("Volumen: &.2lf\n", volumen);
 printf("Oberfläche: %.2lf\n", oberflaeche);
 
 return 0;
 }
 
 
int main () {
 
  printf("UE11 - Köeperberechnung mit Menüfunktionen\n\n");
  {
   while (1 == 1) {
     printf("--------------------");
      
     int wahl;
      
     wahl = getselectMenu();
      
     switch(wahl) {
        
      case 1: {
        calcCube();
        break; }
      case 2: {
        calcCuboid();
        break; }
      case 3: {
         calcSphere();
         break; }
      case 4: {
        return 0; }
      
      }
   }
  }