
#include <stdio.h>
#include <stdlib.h>

double eingabe(char* txt)
{
    char s[80];
    double x;
    double n = 0;
    
    do 
    {
    printf(" %s ", txt);
    n = scanf( "%lf" , &x);
    }while(n =! 1);
    
    return x;
}

double berechnung (double b, double e)
{
  double ergebnis = b;
    
for(int i = 1; i < e; i++)
{
    ergebnis = ergebnis * b;
}    
   

return ergebnis; 

}


int main () 
{

 double basis;
 double exponent;
 double ergebnis;
 
 printf("\tE X P O N E N T I A L R E C H N E R \n\n");

 
 basis = eingabe("Bitte geben Sie die Basis ein: ");
 exponent = eingabe("Bitte geben Sie den Exponenten ein: ");
 

 
 ergebnis = berechnung(basis, exponent);
 
 printf("\n Das Ergebnis lautet: %.lf", ergebnis);
    
    
    
    
    return 0;
}

