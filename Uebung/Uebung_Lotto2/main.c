
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int randZahl(int min, int max)
{
   int zahl;
   
   zahl = (rand() % (max - min + 1)) + min;
    
    
   return zahl;  
    
}

void erstelleFeld(int f[], int groesse, int max, int min)
{
    f[groesse];
    
    for(int i = 0; i < groesse; i++)
    {
        
       do
       { 
        f[i] = randZahl(min, max);
       }while(stellenergleich(f, groesse, f[i]) > 1);
    }
}

void swap(int *a, int *b)
{
    int temp;
    
    temp = *a;
    *a = *b;
    *b = temp;
       
}

void feldsortieren(int f[], int groesse, int anfang)
{
    int temp;
    
    for(int i = 0; i < groesse - 1; i++)
    {
        for(int j = anfang; j < groesse - 1 - i; j++)
        {
            
            if(f[j] > f[j + 1])
            
                swap(&f[j], &f[j + 1]);
            
        }           
    }   
}

void feldumkehren(int f[], int groesse)
{
   int temp; 
    
  for(int i = 0; i < (groesse / 2); i++)
  {
      
      swap(&f[i], &f[groesse - 1 - i]);
      
  }
    
}



void feldausgabe(int f[], char *txt, int groesse)
{
 
    if(groesse > 0)
    printf(" %s: |", txt);
    else
      ;
        
    for(int i = 0; i < groesse; i++)
    {
     
        printf(" %d |", f[i]);
        
    }
}

int zahleingabe(int min, int max, int i)
{
   int eingabe; 
   int n = 0;
   char s[80];
   
   do {
   printf("Bitte Zahl%d eingeben:", i + 1);
   fgets(s, 80, stdin);
   
   n = sscanf(s, " %d", &eingabe);   
   } while(n != 1 || eingabe > max || eingabe < min );
   
   return eingabe;    
}

void feldeingabe(int f[], int groesse, int min, int max)
{
    int h;    
    
    for(int i = 0; i < groesse; i++)
    {
        do{
        f[i] = zahleingabe(min, max, i);
        h = i;
        
        }while(stellenergleich(f, groesse, f[h]) > 1);  
    } 
}

int stellenergleich(int f[], int groesse, int zahl)
{
    int wert = 0;
    
   
    for(int i = 0; i < groesse; i++)
    {
        if (f[i] == zahl)
            wert++;
        
    }
   
    return wert;
}


int felduebereinstimmung(int f[], int f1[], int f2[], int groesse, int anfang)
{
    int zaehler = 0;
    
    for(int i = 0; i < groesse; i++)
    {
        for(int j = 0; j < groesse; j++)
        {
            if(f[i] == f1[j])
            { 
                zaehler++;
                f2[zaehler - 1] = f[i];
            }
        }
        
    }
    if(zaehler == 6)
    printf("\n%d korrekt => gewonnen", zaehler);
    else
        printf("\n%d korrekt\n", zaehler);
    return zaehler;
}

void berechneavg(int f[], int groesse, char *txt, int anfang)
{
    double summe = 0;
    double avg;
    
    for(int i = anfang; i < groesse; i++)
    {
        summe = f[i] + summe;
    }
    
    avg = summe / groesse;
    
    printf("\nMittelwer %s: %.1lf\n", txt, avg);
}


void mini(int f[], int groesse)
{
    int i = 1;
    int mini; 
    int mini2;
  
    if(f[1] > f[0])
    {
        mini = f[1];
        mini2 = f[0];
    }else
        mini = f[0];
        mini2 = f[1];  
    
    for(i = 1; i < groesse; i++) 
    {
        if(f[i] < mini)
        {
           mini2 = mini;
           mini = f[i];  
        }else if(f[i] < mini2)
            mini2 = f[i];
    }  
    
    printf("Kleinster Wert:%d\nZweitkleinster Wert:%d\n", mini, mini2);
    
}

void maxi(int f[], int groesse)
{
    int i = 1;
    int maxi; 
    int maxi2;
    int temp;
    
    
    if(f[1] > f[0])
    {
        maxi = f[1];
        maxi2 = f[0];
    }else
        maxi = f[0];
        maxi2 = f[1];   
    
    
    for(i = 2; i < groesse; i++) 
    {
        if(f[i] > maxi)
        {
           temp = maxi;
           maxi = f[i];
           maxi2 = temp;
        }else if(f[i] > maxi2)
            maxi2 = f[i];
    } 
     printf("Größter Wert:%d\nZweitgrößter Wert:%d\n", maxi, maxi2);
}

int teilfeld(int f[], int groesse, int ug, int og)
{
    feldsortieren(f, groesse, 0);
    int wert = 0;
    
    for(int i = 0; i < groesse; i++)
    {
        if(f[i] >= ug && f[i] <= og)
        {
            wert++;
            swap(&f[i], &f[wert - 1]);
        }
    }  
    feldsortieren(f, groesse, wert);
    
    return wert;
}

void feldspiegeln(int f[], int groesse)
{
    
    
    for(int i = 0; i < groesse / 2; i++)
    {
        
        f[groesse - 1 -i] = f[i];
        
    }
    
}



int main () 
{
   srand(time(NULL)); 
   int groesse = 10;
   int min = 1;
   int max = 100;
   int ug = 20;
   int og = 30;
   int anfang = 0;
   int af = 0;
   
   int z;
   int zaehler = 0;
   int g;
   
   
   
   int f[groesse];
   int f1[groesse];
   int f2[groesse];
   int f3[groesse];
   

   
  erstelleFeld(f, groesse, max, min);
  feldausgabe(f, "Feld unsortiert", groesse);
  printf("\n");
  feldsortieren(f, groesse, anfang);
  feldausgabe(f, "Feld sortiert  ", groesse);        
  feldumkehren(f, groesse); 
  printf("\n");
  feldausgabe(f, "Feld umgekehrt ", groesse);
  printf("\n\n");
  erstelleFeld(f1, groesse, max, min);
  //feldeingabe(f1, groesse, min, max);
  feldausgabe(f1, "Feld eingegeben", groesse);  
  feldsortieren(f1, groesse, anfang);
  printf("\n");
  feldausgabe(f1, "Feld sortiert  ", groesse); 
  feldumkehren(f1, groesse); 
  printf("\n");
  feldausgabe(f1, "Feld umgekehrt ", groesse);
  printf("\n") ;
  
  zaehler = felduebereinstimmung(f, f1, f2, groesse, anfang);
  feldausgabe(f2, "\nFeld gleich", zaehler); 
  printf("\n");
  printf("\n1.Feld:\n");
  berechneavg(f, groesse, "Erzeugtes Feld", anfang); 
  maxi(f, groesse);
  mini(f, groesse);
  printf("\n2.Feld:\n");
  berechneavg(f1, groesse, "Eingegebenes Feld", anfang);
  maxi(f1, groesse);
  mini(f1, groesse);
  
  printf("\n");
  erstelleFeld(f3, groesse, max, min);
  feldausgabe(f3, "Feld unsortiert    ", groesse);
  printf("\n");
  feldsortieren(f3, groesse, anfang);
  feldausgabe(f3, "Feld sortiert      ", groesse);  
  printf("\n");
  af = teilfeld(f3, groesse, ug, og);
  feldausgabe(f3, "Teilfeld umgekehrt ", groesse); 
  feldsortieren(f3, groesse, anfang);
  feldspiegeln(f3, groesse);
  feldausgabe(f3, "\n Teilfeld gespiegelt", groesse); 
  berechneavg(f, af, "der zu Impfenden", anfang);
  
  
    return 0;
}

