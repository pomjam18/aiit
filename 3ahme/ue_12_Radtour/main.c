/* 
 * File:   main.c
 * Author: jan
 *
 * Created on 28. April 2021, 06:58
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct datum{
    int tag;
    int monat;
    int jahr;
};

struct radtour{
    char name[101];
    double laenge;
    int anzahl;
    double hoehenmeter;
    struct datum tour;
};



int eingabeText(char *textausgabe, int len, char *texteingabe)
{
    int ok = 1;
    char s[100];
    do
    {
        if(!ok)
        {
            printf("Ihre eingabe ist zu lang! Bitte reduzieren sie die textlänge auf %d Zeichen!\n", len);
           
        }
        if(textausgabe != NULL)
        printf(textausgabe);
        fgets(s, len, stdin);
        fflush(stdin);
        if( s[0] == '<' )
            return 0;
        ok = (strlen(s) > 0) && (strlen(s) < (len-1));
    }
    while(!ok);
    strcpy(texteingabe, s);
    texteingabe[strlen(s)-1] = '\0';
}

int eingabeGanzeZahl(char *text, int min, int max, int *zahl)
{

int ok = 0;
char s[100];
   
    do{
        if(!ok){
          printf(" Bitte geben sie eine zahl zwischen %d und %d ein", min, max);  
        }
        printf("%s", text);
        fgets(s, sizeof(s), stdin);
        fflush(stdin);
        if(s[0] == '<')
            return 0;
        ok = sscanf(s, "%d", zahl);
        ok &=(*zahl >= min) && (*zahl <= max);
       
    }while(!ok);
   
    return 1;
}

void neueRadtour(struct radtour neuetour[], int *zaehler){
    
    char n[101];
    int max = *zaehler;
    
    do{
        printf("Bitte geben Sie den Name der Radtour ein: ");
        fgets(n, 101, stdin);
        fflush(stdin);

    } while(strlen(n) <= 1 || strlen(n) > 101);

    strcpy((neuetour[max].name), n);

    for (int i = 0; i < max; i++) {

        if(strcmp(neuetour[max].name, neuetour[i].name) == 0) {
            printf("Die Radtour existiert bereits!\n");
            neueRadtour(neuetour, zaehler);
        }
    }
    
    
    printf("Bitte geben Sie das Datum der Radtour ein: ");
    eingabeGanzeZahl("\n\tJahr: ", 2000, 2021, &(neuetour[max].tour.jahr));
    eingabeGanzeZahl("\n\tMonat: ", 1, 12, &(neuetour[max].tour.monat));
    eingabeGanzeZahl("\n\tTag: ", 1, 31, &(neuetour[max].tour.tag));
    
    printf("Bitte geben Sie die Streckenlaenge der Radtour ein: ");
    eingabeGanzeZahl("\n\tStreckenlaenge:", 1, 99999, &(neuetour[max].laenge));

    printf("Bitte geben Sie die Hoehenmeter der Radtour ein: ");
    eingabeGanzeZahl("\n\tHoehenmeter:", 1, 99999, &(neuetour[max].hoehenmeter));

    printf("Bitte geben Sie ein wie oft sie die Radtour gefahren sind: ");
    eingabeGanzeZahl("\n\tAnzahl:", 1, 99999, &(neuetour[max].anzahl));

    (*zaehler)++;
    return;
}

void sortieren(struct radtour sort[], int nummer) 
{
    
    int i, j;
    
    struct radtour *tmp;
    
    tmp = malloc(sizeof(struct radtour *));
    if(tmp == NULL) 
    {
        printf("Alarm!");
        return;   
    } 
    
    for(i = 0; i < nummer; i++) 
    {
        for(j=i+1; j<nummer; j++) 
        {
            
            if(strcmp(sort[i].name, sort[j].name) > 0) 
            {
                
               *tmp = sort[j];
               sort[j] = sort[i];
               sort[i] = *tmp;
            }
        }
    }
}



int deleteTour(struct radtour tour[], int *zaehler)
{
    char s[101];
    char n[2];
    int psuche[100];
    int anzahl = 0; 
    
    printf("Bitte geben Sie die gesuchte Tour ein: ");
    
    do
    {
        fgets(s, 101, stdin);
    }while(strlen(s) <= 1 || strlen(s) > 101);
    
    for(int i = 0; i < zaehler; i++)
    {
        if(strncmp(tour[i].name, s, (strlen(s)- 1)) == 0)
        {
            psuche[anzahl] = i;
            anzahl++;
        }
    }
 printf("%3s   %10s   %15s   %15s   %5s   %15s\n", "Nr.", "Bezeichnung", "Streckenlaenge", "Hoehenmeter[m]", "Anzahl", "Datum");
    printf("--------------------------------------------------------------------------------\n");
    for (int i = psuche[0]; i <= anzahl+psuche[0]; i++) 
    {
        printf("%d  ", i+1);
        printf("%s  ", tour[i].name);
        printf("%lf  ", tour[i].laenge);
        printf("%lf  ", tour[i].hoehenmeter);
        printf("%d  ", tour[i].anzahl);
        printf("%d.%d.%d", tour[i].tour.tag, tour[i].tour.monat, tour[i].tour.jahr);
    }
    if(anzahl>1)
    {
        printf("Bitte konkretere Eingabe!\n");
        deleteTour(tour, zaehler);
    }

    printf("Loeschen? \n Ja...J\nNein...N\n ");
    fgets(n, 2, stdin);
    if (n[0] == 'J' || n[0] =='j') 
    {
        for (int i = psuche[0]; i < *zaehler - 1; i++) 
        {
            tour[i] = tour[i + 1];
        }
        (*zaehler)--;
    }
}
/*
int eingabename( struct radtour *name)
{
     char n[100];
    
    printf("Bitte geben sie den Namen der Tour ein: \n");
     if (eingabeText("", 101, n))
     {
            strcpy(radtour->name, n);
            return 1;
        }
    } 
         
int eingabelaenge( struct radtour *laenge)
{
   
    int l;
    
     printf("Bitte geben sie die Streckenlänge[km] ein:");
     
         if(eingabeGanzeZahl("", 0, 9999, l))
         {
            strcpy(radtour->laenge, l);
            return 1;
            
         }
}
    
int eingabeanzahl( struct radtour *anzahl)
{
   
    int a;
    
     printf("Bitte geben sie die Anzahl wie oft diese Radtour bereits absolviert wurde ein:");
     
         if(eingabeGanzeZahl("", 0, 9999, a))
         {
            strcpy(radtour->anzahl, a);
            return 1;
            
         }
}

int eingabehoehenmeter( struct radtour *hoehenmeter)
{
   
    int h;
    
     printf("Bitte geben sie die gefahrenen Höhenmeter:");
     
         if(eingabeGanzeZahl("", 0, 9999, h))
         {
            strcpy(radtour->hoehenmeter, h);
            return 1;
            
         }
}

int eingabedatum( struct radtour *datum)
{
     char d[100];
    
    printf("Bitte geben sie das Datum[dd.mm.yyyy] der Tour ein: \n");
     if (eingabeText("", 101, d))
     {
            strcpy(radtour->datum, d);
            return 1;
        }
} 

void ausgabetour(struct radtour touren[], int ende, int start) 
{

    printf("%3s   %10s   %15s   %15s   %5s   %15s\n", "Nr.", "Bezeichnung", "Streckenlaenge", "Hoehenmeter[m]", "Anzahl", "Datum");
    printf("--------------------------------------------------------------------------------\n");
    for (int i = start; i < ende; i++) 
    {
        printf("%2d", i+1);
        printf("%14s %18.2lf", touren[i].name, touren[i].laenge);
        printf("%15.2lf", touren[i].hoehenmeter);
        printf("%12d", touren[i].anzahl);
        printf("%2d.%d.%d", touren[i].tour.tag, touren[i].tour.monat, touren[i].tour.jahr);
    }
    return;
}
*/
double eingabe(char *txt)
{
    char s[80];
    char n;
    double wert;
    
    do
    {
    printf("%s ", txt);
     
    fgets(s, 80, stdin);
    n = sscanf(s, "%lf", &wert);
    } while(n != 1);
    
    return wert;
}

void loescheBildschirm()
{
  system("clear"); 
}


int main () 
{
    struct radtour tour[100];
    int zaehler = 0;
    double sum = 0;
    double avg = 0;
    int x = 0;
   
loescheBildschirm();      
    
printf("  \t R A D T O U R\n");
printf("  \t---------------\n\n");
printf("  HAUPTMENÜ\n");
printf("  ---------\n\n");
printf("  1...Neue Radtour\n");
printf("  2...Ausgabe aller Radtouren\n");
printf("  3...Entfernen einer Radtour\n");
printf("  4...Beenden\n");
    

x = eingabe("\n  Ihre Wahl:");

    
    switch(x)
    {
       case 1:
          loescheBildschirm();  
          printf("  \t R A D T O U R\n");
          printf("  \t---------------\n\n");
          printf("  Neue Radtour\n"); 
          printf("  ------------\n\n");
          
           neueRadtour(tour, &zaehler);        
           main();
           break;  
          
       case 2:
          loescheBildschirm();  
          printf("  \t R A D T O U R\n");
          printf("  \t---------------\n\n");
          printf("  Ausgabe aller Radtouren\n\n"); 
          printf("  -----------------------\n\n");
           
           
          for (int i = 0; i < zaehler; i++) 
          {
            sum = sum + (tour[i].laenge * tour[i].anzahl);
          }
          if (zaehler == 0) 
          {
             return;
          }
          avg = sum/(zaehler);
          printf("Die durchschnittliche Streckenlänger aller Toure ist %.2lfkm.\n\n", avg);

          sortieren(tour, zaehler);
           
          printf("%3s   %10s   %15s   %15s   %5s   %15s\n", "Nr.", "Bezeichnung", "Streckenlaenge", "Hoehenmeter[m]", "Anzahl", "Datum");
          printf("--------------------------------------------------------------------------------\n");
           
           for (int i = zaehler; i < 0; i++) 
           {
                printf("%2d", i+1);
                printf("%14s %18.2lf", tour[i].name, tour[i].laenge);
                printf("%15.2lf", tour[i].hoehenmeter);
                printf("%12d", tour[i].anzahl);
                printf("%2d.%d.%d", tour[i].tour.tag, tour[i].tour.monat, tour[i].tour.jahr);
          
           } 
          main();
          break;  
        
       case 3:
           loescheBildschirm();  
           deleteTour(tour, &zaehler);
           main();
          break;     
      
       case 4:
          loescheBildschirm();  
          return 0;
          break;      
    }    
    return 0;
}
