#include <stdio.h>
#include <stdlib.h>

int main () 
{

    int a, b, ergebnis;
    
    printf("\t W A H R H E I T S T A B E L L E\n");
    printf("\t---------------------------------\n");
    printf("\nA\tB\tErgenbnis");
    
    //Werte und Beziehung von A und B können einfach verändert werden!
    
    a = 0; b = 0; ergebnis = !(a&&!b);
    printf("\n%i\t%i\t%i", a, b, ergebnis);
    a = 0; b = 1; ergebnis =! (a&&!b);
    printf("\n%i\t%i\t%i", a, b, ergebnis);
    a = 1; b = 0; ergebnis =! (a&&!b);
    printf("\n%i\t%i\t%i", a, b, ergebnis);
    a = 1; b = 1; ergebnis =! (a&&!b);
    printf("\n%i\t%i\t%i", a, b, ergebnis);
    
    
    return 0;
}

