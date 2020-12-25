
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
/*
 * 
 */




int main () 
{
    int i = 0;
    int anzahl;
    double zahl;
    double summe;
    double avr;
    char s[80];
    int n;
    char eingabe;
    double zaehlermittelwert;
    
    printf("\n\tS T A T I S T I K\n");
    
    printf("\nAddieren ... A");
    printf("\nSubtrahieren ... S");
    printf("\nMultiplizieren ... M");
    printf("\nDividieren ... D\n");
    
    printf("Wahl: ");
    fgets(s, 80, stdin);
    sscanf(s, "%s" , &eingabe);
    
    
    switch( toupper(eingabe))
    {
        
    case 'A':        
    
    do 
    {
    printf("\nWieviele Werte wollen Sie addieren: ");
    fgets(s, 80, stdin);
    sscanf(s, "%i", &anzahl);
    }while(anzahl <= 0);
    printf("\n");
       
    for(i = 1; i <= anzahl; i++)
    {
        do
        {
        printf("Bitte %i. Zahl eingeben: ", i);
        fgets(s, 80, stdin);
        n = sscanf(s, "%lf", &zahl);
        }while(n != 1);
                       
         
        summe = summe + zahl;
    }
    
    
    avr = summe / anzahl;
    
    printf("\nSumme der Eingegebenen Zahlen: %.3lf\n", summe);
    printf("Mittelwert der Eingegebenen Zahlen: %.3lf\n", avr);
    
    break;
    
    case 'S':
            
     do 
    {
    printf("\nWieviele Werte wollen Sie subtrahieren: ");
    fgets(s, 80, stdin);
    sscanf(s, "%i", &anzahl);
    }while(anzahl <= 0);
    printf("\n");
       
    for(i = 1; i <= anzahl; i++)
    {
        do
        {
        printf("Bitte %i. Zahl eingeben: ", i);
        fgets(s, 80, stdin);
        n = sscanf(s, "%lf", &zahl);
        }while(n != 1);
                       
        if(i != 1)
        summe = summe - zahl; 
       
        else
        summe = zahl;
        
        zaehlermittelwert = zaehlermittelwert + zahl; 
    }
    
    
    avr = zaehlermittelwert / anzahl;
    
    printf("\nDiverenz der Eingegebenen Zahlen: %.3lf\n", summe);
    printf("Mittelwert der Eingegebenen Zahlen: %.3lf\n", avr);        
    
    break;
    
    case 'M':
            
       do 
    {
    printf("\nWieviele Werte wollen Sie multiplizieren: ");
    fgets(s, 80, stdin);
    sscanf(s, "%i", &anzahl);
    }while(anzahl <= 0);
    printf("\n");
       
    for(i = 1; i <= anzahl; i++)
    {
        do
        {
        printf("Bitte %i. Zahl eingeben: ", i);
        fgets(s, 80, stdin);
        n = sscanf(s, "%lf", &zahl);
        }while(n != 1);
        
        if(i != 1)
        summe = summe * zahl; 
       
        else
        summe = zahl;
        
        zaehlermittelwert = zaehlermittelwert + zahl; 
    }
    
    
    avr = zaehlermittelwert / anzahl;
    
    printf("\nProdukt der Eingegebenen Zahlen: %.3lf\n", summe);
    printf("Mittelwert der Eingegebenen Zahlen: %.3lf\n", avr);          
    
    break;
    
    case 'D':
    
            
    do 
    {
    printf("\nWieviele Werte wollen Sie dividieren: ");
    fgets(s, 80, stdin);
    sscanf(s, "%i", &anzahl);
    }while(anzahl <= 0 || anzahl == 0 );
    printf("\n");
       
    for(i = 1; i <= anzahl; i++)
    {
        do
        {
        printf("Bitte %i. Zahl eingeben: ", i);
        fgets(s, 80, stdin);
        n = sscanf(s, "%lf", &zahl);
        }while(n != 1);
                       
       if(i != 1)
        summe = summe / zahl; 
       
        else
        summe = zahl;
        
        zaehlermittelwert = zaehlermittelwert + zahl; 
        
    }
    
    
    avr = zaehlermittelwert / anzahl;
    
    printf("\nQuotient der Eingegebenen Zahlen: %.3lf\n", summe);
    printf("Mittelwert der Eingegebenen Zahlen: %.3lf\n", avr);          
    
    break;        
            
    default:
          printf("Fehlerhafte Eingbe!");
    }
    
    
    return 0;
}

