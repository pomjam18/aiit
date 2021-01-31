#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>


int erzeugeZahl()
{

    int zahl = rand()% 57;

  return zahl;
  
}

void punkteSH(int feld[])
{
    
    // 0, 1 , 2, 3, 4, 5, 6, 7, 8
    
    
    for(int i = 0; i < 9; i++)
    {
        feld[i] = erzeugeZahl();
    }
         
}

void punkteAndere(int feld1[])
{
    
    // 0, 1 , 2, 3, 4, 5, 6, 7, 8
    
    
    for(int i = 0; i < 9; i++)
    {
        feld1[i] = erzeugeZahl();
    }
         
}

void differenz(int feld[], int feld1[])
{
    int differenz[9];
    
    for(int i = 0; i < 9; i++)
    {
     
     differenz[i] = feld[i] - feld1[i];
         
    }
    
}
    

void win_lose(int feld[9], int feld1[9],  char winlose[9])
{
   
    
    for(int i = 0; i < 9; i++)
    {
        if(feld[i] > feld1[i])
            winlose[i] = 'w';
        else if(feld[i] < feld1[i])
            winlose[i] = 'l';
        else 
            winlose[i] = 't';
        
    }  
}

void feldsortieren(int feld[])
{
    int temp = 0 ;
    
    
   for(int j = 0; j < 9; j++)
   {
       
       for(int i = 0; i < 9 - j ; i++)
       {
           
           if(feld[i] > feld[i + 1])
           {
               temp = feld[i];
               feld[i] = feld[i + 1];
               feld[i + 1] = temp;
           }
           
           
       }
          
           
   }
    
}

void feldumkehren(int feld[])
{
    int temp;
    
    for(int i = 0; i < 9/2; i++)
    {
        temp = feld[i];
        feld[i] = feld[8 - i];
        feld[8 - i] = temp;
        
    }
    
    
}




void ausgabe(char* txt, int f[])
{
  int i;
  printf("%s\n", txt);
  for (i=0;i<9;i++)
    printf("%d|", f[i]);
  printf("\n");
  
}

void ausgabe1(char* txt, char f[])
{
  int i;
  printf("\n%s\n", txt);
  for (i=0;i<9;i++)
    printf("%c|", f[i]);
  printf("\n");
  
}

int main () {
    srand(time(NULL));

    int feld[9];
    int feld1[9];
    char winlose[9];
    
    punkteAndere(feld1);
    ausgabe("Punkte der Anderen: ", feld1);
    feldsortieren(feld1);
    ausgabe("Sortiert: ", feld1);
    feldumkehren(feld1);
     ausgabe("Umgekehrt: ", feld1);        
    printf("\n");
    
    punkteSH(feld);
    ausgabe("Punkte der Seahawks: ", feld);
     feldsortieren(feld);
    ausgabe("Sortiert: ", feld);
    feldumkehren(feld);
     ausgabe("Umgekehrt: ", feld);        
    printf("\n");
   
    punkteSH(feld);
    punkteAndere(feld1);
    win_lose( feld, feld1, winlose);
    ausgabe1("Winlose ", winlose);

    
    
    return 0;
}

