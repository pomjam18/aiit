

/* 
 * File:   main.c
 * Author: jan
 *
 * Created on 26. April 2021, 14:23
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXPARTEIEN 20   // maximale Anzahl der Parteien
#define MAXMAND 1000     // maximale Anzahl der zu vergebenden Mandate
#define MAXNAMLEN 11     // maximale Länge des Namens einer Partei ist 10 (plus 1 für die abschließende Null!)

int gibGanzeZahlMitUgEin(char* txt, int ug)
{
    char s[80];
    int zahl;

    do{
        printf("%s: ", txt);
        fgets(s, sizeof(s), stdin);
        fflush(stdin);
    }while(sscanf(s, "%d", &zahl)<1 || zahl<ug);

    return zahl;
}

int gibGanzeZahlMitUgUndOgEin(char* txt, int ug, int og)
{
    char s[80];
    int zahl;

    do{
        printf("%s: ", txt);
        fgets(s, sizeof(s), stdin);
        fflush(stdin);
    }while(sscanf(s, "%d", &zahl)<1 || zahl<ug || zahl>og);

    return zahl;
}

void gibStringEin(char* txt, char* eingabe, int maxLen)
{
        printf("%s: ", txt);
        fgets(eingabe, maxLen+1,stdin);
        fflush(stdin);
        eingabe[strlen(eingabe)-1]=0;   //Entfernen des '/n' welchses durch fgets im string landet

}

void eingabe(int* anzPart, int* anzMand, int stimmen[], char namen[][MAXNAMLEN])
{
    char s[80];

    printf("D'Hondt'sches Hoechstzahlverfahren\n"
           "==================================\n");
    *anzPart = gibGanzeZahlMitUgUndOgEin("Anzahl der Parteien",2,MAXPARTEIEN);
    *anzMand = gibGanzeZahlMitUgUndOgEin("Anzahl der Mandate",1, MAXMAND);
    for(int i=0;i<*anzPart;i++)
    {
        sprintf(s,"Name der %d.Partei",i+1);
        gibStringEin(s,namen[i],MAXNAMLEN);
        sprintf(s,"Stimmen %s",namen[i]);
        stimmen[i]=gibGanzeZahlMitUgEin(s,0);
    }

}

int main()
{
    int stimmen[MAXPARTEIEN];               // Anzahl der Stimmen jeder Partei (Eingangsgröße)
    int mandate[MAXPARTEIEN];               // Anzahl der Mandate jeder Partei (Ausgangsgröße)
    double tabelle[MAXMAND][MAXPARTEIEN];   // Tabelle für das Höchstzahlverfahren (berechnete Größe)
    char name[MAXPARTEIEN][MAXNAMLEN];      // Namen der Parteinen (Eingangsgröße)

    int anzPart;  // Anzahl der Parteien
    int anzMand;  // Anzahl der Mandate

    eingabe(&anzPart, &anzMand, stimmen, name);

    return 0;
}
