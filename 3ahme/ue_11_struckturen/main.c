/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: jan
 *
 * Created on 8. April 2021, 14:01
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_ANZAHL_SCHUELER 24

struct Name{
    char nachname[30];
    char vorname[30];
};

struct Datum{
    int tag;
    int monat;
    int jahr;
};

struct anschrift{
    char strasse[30];
    char ort[30];
    int plz;  
};

struct Schuelerdaten{
    struct name schuelername;
    struct datum geburtsdatum;
    struct anschrift schueleranschrift;    
};

void ausgabeSchueler(struct Schuelerdaten gruppe[], int anzahl){
   
    printf("Die Gruppe umfasst folgende Schueler:\n");
    printf("============================================================================");
   
    for(int i = 0; i < anzahl; i++){
        printf("\n%d. %s %s  | %d.%d.%d  | %s %s %d ", i+1,
               gruppe[i].schuelername.vorname, gruppe[i].schuelername.nachname, //Name
                gruppe[i].geburtsdatum.tag, gruppe[i].geburtsdatum.Monat, gruppe[i].geburtsdatum.jahr, // geburtstag
                gruppe[i].schueleranschrift.strasse, gruppe[i].schueleranschrift.ort, gruppe[i].schueleranschrift.plz); //Datum
    }
}

int eingabeGanzeZahl(char *text, int min, int max, int *zahl){

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
int eingabename( struct name *schuelername)
{
     char sv[100], sn[100];
    
    printf("Bitte geben sie den Namen ein: \n");
     if (eingabeText("Vorname: ", 19, sv))
     {
        if (eingabeText("Nachname: ", 19, sn))
        {
            strcpy(schulername->nachname, sn);
            strcpy(schulername->vorname); sv);
            return 1;
        }
    } 
         
}

int eingabeAnschrieft( struct anschrieft *anschrieft)
{
    char so[100], str_s[100];
    int plz;
    
     printf("Bitte geben sie die Anschrieft ein: \n");
     if (eingabeText("Strasse: ", 29, str_s))
     {
         if(eingabeGanzeZahl("PLZ: ", 1000, 9999, plz))
         {
             
            if (eingabeText("Ort: ", 29, so))
            {
            strcpy(anschrieft->strasse, str_s);
            strcpy(anschrieft->ort); so);
            strcpy(anschrieft->plz); plz);
            return 1;
            }
        }
     }
    
}

int neueschueler(struct schuelerdaten schueler[], int *anzahl)
{
    if (!eingabename(&schueler[*anzahl].schuelername) == 0)
        return 0;
    if (!eingabeAnschrieft(&schueler[*anzahl].schueleranschrieft))
        return 0;
    if (!eingabeGeburtsdatum(&schueler[*anzahl].geburtsdatum))
        return 0;
    
    *anzahl = *anzahl + 1;
    return 1;
}

int eingabeGeburtsdatum(struct Datum *geburtsdatum)
{
    int ok = 1;
    int jahr;
    int monat;
    int tag;
    
    printf("Bitte geben sie das Geburtsdatum ein: \n");
    
    if (eingabeGanzeZahl("Jahr: ", 1980, 2003, &jahr))  
    {
        if (eingabeGanzeZahl("Monat: ", 1, 12, &monat))
        {
             if (eingabeGanzeZahl("Tag: ", 1, 31, &tag)) 
             {
                 geburtsdatum->jahr  = jahr;
                 geburtsdatum->monat  = monat;
                 geburtsdatum->tag  = tag;
                 return 1;
             }
        }
    } 
  return 0;  
}

int eingabeText(char *textausgabe, int len, char *texteingabe)
{
    int ok = 1;
    char s[100];
    do
    {
        if(!ok)
        {
            printf("Ihre eingabe ist zu lang! Bitte reduzieren sie die textlänge auf %d Zeichen!\n", len);
            //-> strlen könnte man die aktuelle Textlänge hinweisen!
        }
        if(textausgabe != NULL)
        printf(textausgabe);
        fgets(s, len, stdin); //"irgendwas\n"
        fflush(stdin);
        if( s[0] == '<' )
            return 0;
        ok = (strlen(s) > 0) && (strlen(s) < (len-1));
    }
    while(!ok);
    strcpy(texteingabe, s);
    texteingabe[strlen(s)-1] = '\0'; //Eleminierung der Enter-Taste
}



void eingabeAdresse(){
   
}

void eingabeSchueler(){
   
}

int main (int argc, char** argv) {

    struct Schuelerdaten aiit_schuelerliste[MAX_ANZAHL_SCHUELER] = {
        {{"Kurzmann", "Jakob"}, {11, 11, 2003}, {"Murbergstraße 39", "Fernitz-Mellach", 8072}} ,
        {{"Kurzmann", "Josef"}, {11, 11, 2003}, {"Murbergstraße 39", "Fernitz-Mellach", 8072}} ,
    };
    int schueleranzahl = 2;
   
    ausgabeSchueler(aiit_schuelerliste, schueleranzahl);
    return 0;
}

