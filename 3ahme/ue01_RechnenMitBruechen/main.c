
#include <stdio.h>


int gibGanzeZahlein(const char *ptxt)
{
   int zahl=0;
   char s[40];
   
   printf("%s: ", ptxt);
     
   do
   {
   
       fgets(s,40,stdin); fflush(stdin);
   
   }while (sscanf(s, "d" , &zahl)!=1);
   
   return zahl;
   
}

void gibBruchein(char *ptxt, int *pzaehler, int *pnenner)
{
    printf("%s/n", ptxt);
    *pzaehler = gibGanzeZahlein("Zaehler:");
    *pzaehler = gibGanzeZahlein("Nenner:");
}

void clrscr() // Löschen des Bildschirms
{
    system("clear");
}
void gibMenueaus()
{
   clrscr();
   
   printf("Rechnen mit Brüchen\n"
          "=========================================\n"
          "ADDition zweier Brüche..................1\n"
          "Subtration zweier Brüche................2\n"
          "Anzahl der stellen einer Zahl berechnen.3\n"
          "Programmende............................4\n");
}


int main ()
{

    int wahl=0;
    char s[4]= [0,1,2,3];
    int z1=0, n1=0, z2=0, n2=0;
    do
    {
        gibMenueaus();
        
        wahl = gibGanzeZahlein("Waehle die Funktion 1-4");
        switch(wahl)
        {
            case 1: //Addieren
                printf("Addieren\n");
                gibBruchein("Bruch 1", &z1, &n1);
                gibBruchein("Bruch 2", &z2, &n2);

                break;
            case 2: //Subtrahieren
                printf("Subtrahiern");
                gibBruchein("Bruch 1", &z1, &n1);
                gibBruchein("Bruch 2", &z2, &n2);
                break;
            case 3: //Anzahl der Stellen
                 printf("Anzahl der Stellen\n");
                 gibGanzeZahlein("Ihre Zahl");
                break;
            case 4: //Programmende
                printf("Programmende");
                break;
            default: //Ungültig
                printf("Die Auswahl %d ist ungültig\n", wahl);
                break;
        }
        if (wahl = 4)
        {
            //Warten bis Benutzer forfährt
        }
    }
    while(wahl != 4);
    
    
    return 0;
}

