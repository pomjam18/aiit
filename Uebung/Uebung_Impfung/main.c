#include <stdio.h>
#include <stdlib.h>


int randzahl(int ug, int og)
{
    return rand() %  (og - ug + 1) + ug;    
}

int erstellefeld(int f[], int size, int ug, int og)
{
    for(int i= 0; i < size; i++)
    {
    f[i] = randzahl(ug, og);
    }     
}

int zahleingabe(int min, int max, int i)
{
    char s[80];
    int eingabe;
    int n;
    
    
    do{
    printf("\nAlter %d:", i + 1);
    fgets(s, 80, stdin);
    n = sscanf(s, "%d", &eingabe);
    }while(n = 0 || eingabe > max || eingabe < min);
       
    return eingabe;
}

void eingabeFeldErstellen(int f[], int size, int min, int max)
{
    for(int i = 0; i < size; i++)
    {
        f[i] = zahleingabe(min, max, i);
    }    
}

void feldausgabe(int f[], int size, char *txt, int start )
{
    printf("\n%s|", txt);
    for(int i = start; i < size; i++)
    {
      printf(" %d |", f[i]);  
    }
}

void swap(int *a, int *b)
{
    int temp = 0;
    
    temp = *a;
    *a = *b;
    *b = temp;
    
}

void feldsortieren(int f[], int size, int anfang)
{
    for(int i = 0; i < size - 1; i++)
    {
        for(int j = anfang; j < size - 1 -i; j++)
        {
            if(f[j] > f[j + 1])
                swap(&f[j], &f[j + 1]);   
        }   
    }   
}

void feldumkehren(int f[], int size)
{
    
   for(int i = 0; i < size / 2; i++)
   {
       swap(&f[i], &f[size - 1 - i]);     
   }
    
}

void mini(int f[], int size)
{
   int mini = 0;
   int mini2 = 0;
    
   
    if(f[0] < f[1])
    {
        mini = f[0];
        mini2 = f[1];
    }else 
    {  mini = f[1];
       mini2 = f[0];
    }
    
    
    for(int i = 2; i < size; i++)
    {
        if(f[i] < mini)
    {
        mini2 = mini;
        mini = f[i];  
    }else if(f[i] < mini2)
        mini2 = f[i];
        
    }
    
    printf("\nKleinstes Alter: %d", mini);
    printf("\nZweitkleinstes Alter: %d", mini2);
}

void maxi(int f[], int size)
{
   int maxi = 0;
   int maxi2 = 0;
    
   
    if(f[0] > f[1])
    {
        maxi = f[0];
        maxi2 = f[1];
    }else 
    {  maxi = f[1];
       maxi2 = f[0];
    }
    
    
    for(int i = 2; i < size; i++)
    {
        if(f[i] > maxi)
    {
        maxi2 = maxi;
        maxi = f[i];  
    }else if(f[i] > maxi2)
        maxi2 = f[i];
        
    }
    
    printf("\nGrößtes Alter: %d", maxi);
    printf("\nZweitgrößtes Alter: %d", maxi2);
}

void feldspiegeln(int f[], int size)
{
    
    for(int i = 0; i < size / 2; i++)
    {
        f[size - 1 - i] = f[i];       
    }
}

void feldspiegeln2(int f[], int size)
{
    
    for(int i = 0; i < size / 2; i++)
    {
        f[i] = f[size / 2 + i];       
    }
}

void feldverschieben(int f[], int size)
{
    
    for(int i = 0; i < size / 2; i++)
    {
        swap(&f[i], &f[size / 2 + i]);        
    }
}

int teilfeld(int f[], int size, int min, int max)
{
    int wert = 0;
    
   feldsortieren(f, size, 0);
    
    for(int i = 0; i < size; i++)
    {
        if(f[i] < max && f[i] > min)
        {
          wert++;
          swap(&f[i], &f[wert - 1]);
          
        }
    }    
    feldsortieren(f, size, wert);
    return wert;
}

void feldkopieren(int f[], int f1[], int size)
{
    for(int i = 0; i < size; i++)
    {
        f1[i] = f[i];
    }
}

void avg(int f[], int size, int anfang, int ende, int *av)
{
    int summe = 0;
    int z;
    
    
    for(int i = anfang; i < ende ; i++)
    {
        summe = summe + f[i];
       
    }
    
    *av = summe / (ende - anfang);
    printf("\n%d\n", summe);
    
    printf("\n%d\n", *av);
}


int main () 
{
    srand(time(NULL));
    
    
    int size = 20;
    int ug = 10; //kleinste Zahl
    int og = 100; //größte Zahl
    int start = 0;
    int min = 50; //min Impfalter
    int max = 70; //max Impfalter
    
    int anzahl = 0;
    int av = 0;
    
    int f[size];
    int f1[size];
    
    
    
    erstellefeld(f, size, ug, og);
    feldausgabe(f, size, "Feld1 Unsortiert: ", start);
    feldsortieren(f, size, 0);
    feldkopieren(f, f1, size);
    feldausgabe(f, size, "Feld1 Sortiert:   ", start);
    feldumkehren(f, size);
    feldausgabe(f, size, "Feld1 Umgekehrt:  ", start);
    feldspiegeln(f, size);
    feldausgabe(f, size, "Feld1 Gespiegelt: ", start);
    feldspiegeln2(f, size);
    feldausgabe(f, size, "Feld1 Gespiegelt2:", start);
    feldverschieben(f, size);
    feldausgabe(f, size, "Feld1 verschoben: ", start);
    printf("\n");
    feldkopieren(f1, f, size);
    mini(f, size);      
    maxi(f, size); 
    printf("\n\nAlter zwischen %d und %d:", min, max);
    anzahl = teilfeld(f, size, min, max);
    feldausgabe(f, size, "Feld1 Alter vorsortiert: ", start); 
    
    avg(f, size, 0, anzahl, &av);
    printf("\nDas Durchschnittsalter der zwischen %d und %d Jährigen: %d", min, max, av);
    avg(f, size, anzahl + 1, size, &av);
    printf("\nDas Durchschnittsalter der Anderen: %d", av);
    
    return 0;
}

