
#include <stdio.h>
#include <stdlib.h>


int main () 
{
    int temp;
    
    
    
  printf("\t A G G R E G A T Z U S T A N D - W A S S E R\n");

printf("\nWassertemperatur bitte eingeben: ");  
scanf("%i", &temp);

printf("Aggregatzustang: ");

if(temp < 0)
{
    printf("Gefroren");
}
else if(temp >=0 && temp < 100)
{
    printf("Flüssig");
}    
else if(temp >= 100)
{
    printf("Gasförmig"); 
}
else
{
    printf("Fehlerhafte Eingabe!");
}  






    
    
    return 0;
}

