/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main () {

    int i = 0;
    char passwort[99];
    char passwort2[99];
    
    printf("\nBitte ein Passwort eingeben:");
    gets(passwort);
    
    printf("%lu", sizeof(passwort));
    
    printf("\nBitte das Passwort bestätigen:");
    gets(passwort2);
    
    if(strcmp(passwort,passwort2) == 0)
    {
        printf("\nPasswort OK\n");
    }
    else
        printf("\nPasswort falsch!\n");
    
    int w = strcmp(passwort,passwort2);
     printf("\n %d\n", w);
 
       int zahl = 1;
     
     while(passwort[i] =! '\0')
     {
       
         zahl++;
         i++;
        
     }
  printf("%d", zahl);

    
    int ergebnis, zahle;
    char eingabe[80];
    
    printf("\nBitte eine Ganzzahl eingeben: ");
    gets(eingabe);
    ergebnis = atoi(eingabe);
    printf("Der Wert ist %i\n",ergebnis);
     
     
     
     return 0;
}
*/

#include<stdio.h>
#include <string.h>
# include <ctype.h>
#define _CRT_SECURE_NO_WARNINGS

int main (void)
{

//Variablendeklaration
char Textzeile[81];
int laenge;


do
{
//Eingabeaufforderung
printf("Bitte einen max. 80 Zeichen langen Text eingeben:");

//String einlesen
gets(Textzeile);

//Zeichen insgesamt zählen
laenge=strlen(Textzeile);
printf("\n---Laenge des Strings = %i Zeichen---\n",laenge);
if(laenge>80)
{
printf("\nSie haben mehr als 80 Zeichen eingegeben\n");
}
//Ausgabe zur Kontrolle
printf("\nSie gaben \"%s\" ein.\n",Textzeile);

}
while(laenge>80);

}


