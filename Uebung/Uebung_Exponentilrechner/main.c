
#include <stdio.h>
#include <stdlib.h>

double eingabe(char txt)
{
    char s[80];
    double x;
    
    
    printf(" %c ", txt);
    scanf( "%lf" , &x);
    
    return x;
}

double berechnung (double b, double e)
{

for(int i = 0; i < e; i++)
{
    b = b * b;
}    
   
double ergebnis = b;
return ergebnis; 

}


int main () 
{

 double basis;
 double exponent;
 double ergebnis;
 
 basis = eingabe("Bitte geben Sie die Basis ein: ");
 exponent = eingabe("Bitte geben Sie den Exponenten ein; ");
 
 ergebnis = berechnung(basis, exponent);
 
 printf(" Das Ergebnis lautet: %lf", ergebnis);
    
    
    
    
    return 0;
}

