
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/*
 * 
 */
int main () 
{
    char eingabe;
    char s[80];
    int zahl;
    printf("\t Z A H L E N U M W A N D L E R\n");
    printf("\t-------------------------------");
    
    printf("\n\nWählen Sie ein Zahlensystem aus:\n\n Oktal ... O\n Hexadezimal ... H\n ASCII ... A\n");
    
   
    printf("Wahl: ");
    fgets(s, 80, stdin);
    sscanf(s, "%s" , &eingabe);
    toupper(eingabe);
    
    printf("Bitte Dezimalzahl eingeben: ");
    fgets(s, 80, stdin);
    sscanf(s, "%i" , &zahl);
    
    switch(eingabe)
    {
        case 'O':
            printf("Dezimal: %i = Oktal: %o \n",zahl, zahl);
            
            break;
        
        case 'H':
            printf("Dezimal: %i = Hexadezimal: %x \n", zahl, zahl);
            
            break;
            
        case 'A':
            if(zahl <= 255)
              printf("ASCII Code %i entspricht %c \n", zahl, zahl);
            
            else
              printf("\nDiese Zahl ist leider zu groß!\n\a");
            
            break;
            
        default:
            printf("Falsche EIngabe!");
                       
    }    
    
    return 0;
}

