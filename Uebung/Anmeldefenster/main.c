
#include <stdio.h>
#include <stdlib.h>

/*char feldInitalisieren(char *txt, char *array[100])
{
    char eingabe;
   
   
    printf("%s", txt);
    sscanf( "%c", &eingabe);
    
    array[100] = {"%c", eingabe};
    
    
    
    
    return array[100];
    
}
 */

int main () 
{

    int i;
    double noten[15];
    double anzahl = 15, summe = 0;
    
    

    
    for(i = 0; i < anzahl; i++)
    {
            printf("\nGeben sie ihre Note ein: ");
            scanf("%lf", &noten[i]);
            
    }
    for(i = 0; i < anzahl; i++)
    {
        summe = summe + noten[i];
        
    }
    printf("\nSumme: %4.2lf", summe);
    printf("\n\nDurchschnitt: %4.2lf", summe / anzahl);

    return 0;
}

