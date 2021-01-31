
#include <stdio.h>
#include <stdlib.h>



int erzeugeZahl(int min, int max) 
{
    int zahl;
    
    
    zahl = (rand() % ((max + 1) - min)) + min;
   
    
}

int gibZahlein(int i) 
{
   int eingabe; 
   int n=0;
   char s[80];
   
   do {
   printf("Bitte Zahl%d eingeben:", i);
   fgets(s, 80, stdin);
   
   n = sscanf(s, " %d", &eingabe);   
   } while(n != 1 );
   
   
   return eingabe;
    
}

void felderstellen(int f[], int min, int max)
{

    
    for(int i = 0; i < 6; i++)
    {
        f[i] = erzeugeZahl(min, max);
    }
        
        
}

void feldeingabe(int f1[])
{

    int z = 0;
 
    for(int i = 1; i < 7; i++)
    {
       do {
      f1[i] = gibZahlein(i);    
      } while(f1[i] > 46 || f1[i] < 1);
    }
            
}

void feldvergleichen(int f[], int f1[], int f2[], int zaehler)
{
    f[6];
    f1[6];
    f2[6];
    zaehler = 0;
    
    for(int i = 0; i < 6; i++)
    {
        for(int j = 0; j < 6; j++)
        {
          if(f1[i] == f[j])
          {
              f2[i] = f1[i];
              zaehler++;
              break;
          }            
        }   
    }
   /* if(zaehler==6) {
        printf("Gewonnen\n");
        
    }else {
        printf("%d Richtig\n", zaehler);
    }*/
}

void feldausgabe(int f10[], int zaehler)
{
    f10[6];
    
      
    
    if(zaehler > 0)
    {
    for(int i = 0; i < 6; i++)
    {
        
     printf("%d|", f10[i]);
    }
    }
}



int main () 
{
    srand(time(NULL));
    
    int f[6];
    int f1[6];
    int f2[6];
    int zaehler = 0;
    int g = 0;
    
    for(int i = 0; i < 10000000; i++)
    {
   felderstellen( f, 1, 46);
   felderstellen( f1, 1, 46);
    
   feldvergleichen( f, f1, f2, &zaehler);
   if(zaehler > 0)
       g++;
   }
    printf("%d", g);
    
  return 0;
}

