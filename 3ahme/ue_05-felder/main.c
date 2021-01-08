#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100

// Ganzzahlige ZZ berechnen
int berechneGanzeZZ(int ug, int og)
{
    int rv = (rand() %(og - ug + 1)) +ug;

  return rv;
}

// FK ZZ berechnen
double berechneFkZZ(double ug, double og)
{
   double r = og - ug;

  return ug + (double)(r * rand()/(RAND_MAX)); 
}

// Feld erstellen mit 20 bis 60 Zahlen zwischen 50 und 250
int feldErstellen(double f[])
{
  int z = berechneGanzeZZ(20, 60);

 

  for (int i = 0; i < z; i++) {

    f[i] = berechneFkZZ(50, 250);

  }

  return z;
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
anzahl = anzahl -1;

  double tmp = 0;

 

  for (int i = 0; i <=  (anzahl / 2); i++) {

    tmp = f[i];

    f[i] = f[anzahl - i];

    f[anzahl - i] = tmp;

  }
}

// Finde zweitgrößte und zweitkleinste Zahl im Feld
void miniMax2(double f[], int anzahl, double* mini2, double* maxi2)
{
   int miniZahl = 1;

  int maxiZahl = anzahl - 2;

 

  *mini2 = f[miniZahl];

  *maxi2 = f[maxiZahl];
}

void bubbleSort(double f[], int anzahl)
{
 double tmp;

 

  for (int i = 1; i < anzahl; i++) {

    for (int j = 0; j < anzahl - 1 - i; j++)  {

      if (f[j] > f[j + 1]) {

          tmp = f[j];

          f[j] = f[j + 1];

          f[j + 1] = tmp;
      }
    }
  }
}

void merge(double f[], int links, int mitte, int rechts)
{
    //Teilfelder, also Feld links von der Mitte und rechts von der Mitte auf ein temporäres neues Feld kopieren

    double l[MAX], r[MAX]; //linkes und rechtes Hilfsfeld

    int i,j, k;
    int nl = mitte - links + 1;
    int nr = rechts - mitte;

    //Schritt 1: kopieren der Original-Daten auf die Hilfsfelder
    for (i = 0; i < nl; i++)
        l[i] = f[links +i];

    for (j = 0; j < nr; j++)
        r[j] = f[mitte + 1 + j];

    //Schritt 2: Sortiert zurück ins Feld kopieren
    i = 0;
    j = 0;
    k = links;
    while( (i < nl) && (j < nr))
    {
        if(l[i] > r[j])
        {
            f[k] = r[j];
            j++;
            k++;
        }
        else
        {
            f[k] = l[i];
            i++;
            k++;
        }
    }
    //Restlichen Elemente vom linke oder rechten Feld in das Hauptfeld zurückspeichern
    while( (i < nl) )
        f[k++] = l[i++];
    while( (j < nr) )
        f[k++] = r[j++];
}

void mergeSort2(double f[], int links, int rechts)
{
    if(links < rechts)
    {
        int mitte = links + (rechts - links)/2;

        mergeSort2(f, links, mitte);
        mergeSort2(f, mitte + 1, rechts);

        //Sortierung
        merge(f, links, mitte, rechts);
    }

}

void mergeSort(double f[], int anzahl)
{
    mergeSort2(f, 0, anzahl-1);
}


int main(int argc, char** argv)
{
  double f[MAX];    // Feld
  int anzahl = 0;   // Anzahl der Zahlen im Feld
  double mini, maxi, mini2, maxi2;
  
  // ZZG initialisieren
  srand(time(NULL));
  anzahl = feldErstellen(f);    // Feld erstellen
  
  
    anzahl = feldErstellen(f);

  feldAusgabe("Feld:", f, anzahl);

  feldUmkehren(f, anzahl);

  feldAusgabe("\nFeld umgekehrt:", f, anzahl);

  bubbleSort(f, anzahl);

  feldAusgabe("\nFeld sortiert:", f, anzahl);

  miniMax2(f, anzahl, &mini2, &maxi2);

  printf("Zweitkleinste Zahl: %lf\nZweitgrößte Zahl %lf\n", mini2, maxi2);

  mergeSort(f, anzahl);
  
   feldAusgabe("\nMerge Sort:\n", f, anzahl);
  

return 0; 
}