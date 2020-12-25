
#include <stdio.h>
#include <stdlib.h>

int main () 
{
    int jahr, monat, tage;
  
    printf("\tK A L E N D E R\n");
    printf("\nBitte Jahr eingeben: ");
    scanf("%i", &jahr);
    printf("Bitte Monat eingeben: ");
    scanf("%i", &monat);
    
    if(monat >= 1 && monat <= 12 && jahr > 1582)
    { 
        switch (monat)
        {
            case 2:
                if(!((jahr%100)%4) && (jahr%100) || (jahr%400))
                    tage = 29;
                else
                    tage = 28;
                break;
            case 4:
            case 6:
            case 9: case 11:
                tage = 30;
                break;
            default:
                tage = 31;
        }
               
        printf ("\n%i hat der Monat %i %i Tage", jahr, monat, tage);
    }
    else 
        printf("Falsche Datumseingabe!");    
    
    return 0;
}

