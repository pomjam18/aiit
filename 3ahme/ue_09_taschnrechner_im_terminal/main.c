#include <stdio.h>
#include <stdlib.h>
#include <string.h>


double findeMax(double f[], int anzahl) 
{
  double max;
  max = f[0];
 
  for (int i = 1; i < anzahl; i++) 
  {
    if (f[i] > max) 
    {
      max = f[i];
    }
  }
  
  return max;
}


double findeMin(double f[], int anzahl) 
{
  double min;
  min = f[0];
 
  for (int i = 1; i < anzahl; i++) 
  {
    if (f[i] < min) 
    {
      min = f[i];
    }
  }
  
  return min;
}


double berechneSumme(double f[], int anzahl) 
{
  double summe = 0;
  for (int i = 0; i < anzahl; i++) 
  {
    summe = summe + f[i];
  }
  
  return summe;
}


double berechneAvg(double f[], int anzahl) 
{
  double summe = berechneSumme(f, anzahl);
  double avg = (summe / anzahl);
  
  return avg;
}


void ausgabe(double f[], int anzahl) 
{
 
  for (int i = 0; i < anzahl; i++) 
  {
    if (f[i] =! NULL) 
    {
      if (i == 0) 
      {
        printf(" Minimum: %lf", f[i]);
      }
    }
  }
}


void sucheBefehl(char *f[], int anzahlFeld, double rv[], double ergebnis[]) 
{
  int summe;
  int avg;
  int min; 
  int max;
  int zaehler = 0;
  int n;
  double pruefer;
 
  for (int i = 0; i < anzahlFeld; i++) 
  {
    min = strcmp(f[i], "-min");
    
    if(min == 0) 
    {
      for (int j = i + 1; j < anzahlFeld; j++ ) 
      {
          n = sscanf(f[j], "%lf", &pruefer);
          if (n == 1) {
            rv[zaehler] = pruefer;
            zaehler++;
          }
      }
      ergebnis[0] = findeMin(rv, (zaehler + 1));
    }
    
    zaehler = 0;
    max = strcmp(f[i], "-max");
    
    if(max == 0) 
    {
      for (int j = i + 1; j < anzahlFeld; j++) 
      {
          n = sscanf(f[j], "%lf", &pruefer);
          
          if (n == 1) 
          {
            rv[zaehler] = pruefer;
            zaehler++;
          }
      }
      
      ergebnis[1] = findeMax(rv, (zaehler + 1));
    }
    
    zaehler = 0;
    summe = strcmp(f[i], "-sum");
    
    if(summe == 0) 
    {
      for (int j = i + 1; j < anzahlFeld; j++ ) 
      {
          n = sscanf(f[j], "%lf", &pruefer);
          if (n == 1) 
          {
            rv[zaehler] = pruefer;
            zaehler++;
          }
      }
      
      ergebnis[2] = berechneSumme(rv, (zaehler + 1));
    }
    
    zaehler = 0;
    avg = strcmp(f[i], "-avg");
    
    if(avg == 0) 
    {
      for (int j = i + 1; j < anzahlFeld; j++ ) 
      {
          n = sscanf(f[j], "%lf", &pruefer);
          if (n == 1) 
          {
            rv[zaehler] = pruefer;
            zaehler++;
          }
      }
      
      ergebnis[3] = berechneAvg(rv, (zaehler + 1));
    }
  }
}


int main (int argc, char* argv[]) 
{
  double rv[100];
  double ergebnis[4];

  sucheBefehl(argv, argc, rv, ergebnis);
  
  for (int i = 0; i < 4; i++) 
  {
    printf(" %.2lf ", ergebnis[i]);
  }  
  
  return 0;
}
