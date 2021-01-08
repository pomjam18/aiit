
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100

// Ganzzahlige ZZ berechnen
int berechneGanzeZZ(int ug, int og)
{
    
    
    
}

// FK ZZ berechnen
double berechneFkZZ(double ug, double og)
{
}

// Feld erstellen mit 20 bis 60 Zahlen zwischen 50 und 250
int feldErstellen(double f[])
{
    
  anzahl = rand  
    
  for(int i = 0; i < anzahl, i++)
  {
      
  }
    
    
    
    
    
	return 0;
}


void feldAusgabe(char* txt, double f[], int anzahl)
{
  int i;
  printf("%s\n", txt);
  for (i=0;i<anzahl;i++)
    printf("%8.3lf", f[i]);
  printf("\n");
  if ((anzahl % 10) > 0)
    printf("\n");
}

// Reihenfolge der Feldelemente im Feld umkehren
void feldUmkehren(double f[], int anzahl)
{

}

// Finde zweitgrößte und zweitkleinste Zahl im Feld
void miniMax2(double f[], int anzahl, double* mini2, double* maxi2)
{
  
}

void bubbleSort(double f[], int anzahl)
{

}

int main(int argc, char** argv)
{
  double f[MAX];    // Feld
  int anzahl = 0;   // Anzahl der Zahlen im Feld
  double mini, maxi, mini2, maxi2;
  
  // ZZG initialisieren
  srand(time(NULL));
  anzahl = feldErstellen(f);    // Feld erstellen
  
  
  return (EXIT_SUCCESS);
}