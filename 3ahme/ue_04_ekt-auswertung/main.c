#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MDATA_MAX_SIZE   1000
#define MOVINGAVERAGING_WINDOW_SIZE   10
#define NO_ERROR 0
#define OUT_OF_MEMORY_ERROR 1
#define FILE_ERROR 2
#define Fenster 4

void genSinusWithNoise(double f[], int length, double length_period, double amplitude, double offset, double amplitude_noise)
{
    for (int i = 0; i < length; ++i)
    {
        f[i] = amplitude * sin(2*M_PI/length_period * i);
        f[i] += offset;
        f[i] += (rand() % 100) * amplitude_noise/100;
    }
}

int readDataFromFile(char *filepath, double *mdata, int max_length, int *length)
{
  int idummy = 0;
  double ddummy = 0;
 
  FILE* f = fopen(filepath, "r");
  if (f==NULL)
    return FILE_ERROR;
 
  *length = 0;
  while (!feof(f) && (*length < max_length))    // Solange Dateiende NICHT erreicht ist
  {
    char s[100];
    if (fgets(s,100,f) == NULL)   // Nächste Zeile einlesen
      break;
   
    if (sscanf(s,"%d;%lf;%lf", &idummy, &mdata[*length], &ddummy) == 3)
        (*length)++;

  }
 
  fclose(f);
  return NO_ERROR;
}

int writeData2File(char *filepath, double data[], int length)
{
  FILE* f = fopen(filepath, "w");
  if (f == NULL)
    return FILE_ERROR;
  for (int i=0;i<length;i++)
    fprintf(f,
      "%.3f\n", data[i]
    );
  fclose(f);
  return NO_ERROR;
}

double removeOffset(double f[], int length)
{
  double sum = 0;
  double offset = 0;
   
  for(int i = 0; i < length; ++i)
  {
    sum += f[i];
  }
 
  offset = sum/length;
   
  for(int i = 0; i < length; ++i) {
   
    f[i] -= offset;
  }
  return offset;
}

void calcMovingAveraging(double f[], int length) {
 
  double sum=0;
  double avg=0;
 
  for(int i = 0; i < MOVINGAVERAGING_WINDOW_SIZE; i++)
  {
      sum += f[i];
  }
 
  for(int i = 0; i < (length - MOVINGAVERAGING_WINDOW_SIZE); i++)
  {
    avg = sum / MOVINGAVERAGING_WINDOW_SIZE;
    sum += f[i + 10];
    sum = sum - f[i];
    f[i] = avg;
  }
}

void diffSignal(double f[], int length)
{
    for(int i = 0; i < 999; i++)
    {
        f[i] = f[i + 1] - f[i];
    }
}

double normalizeSignal(double f[], int length)
{
    double max = 0;
    double r;
    
    for (int i = 0; i < length; i++) {
    
    if (abs(f[i]) > max) {
      
      max = abs(f[i]);
    }
  }
  
  for(int i = 0; i < length; i++) {
    
    f[i] = f[i] / max;
    r = round(f[i]);
    f[i] = r;
  }
  return 0;
    }


int main ()
{
  double f[999];
  int lenght = 999;
  
  readDataFromFile("mdata.csv", f, lenght, &lenght);
  writeData2File("EKG1.csv", f, lenght);
  double offset = removeOffset(f, lenght);
  calcMovingAveraging(f, lenght);
  writeData2File("EKG2.csv", f, lenght);
  diffSignal(f, lenght);
  normalizeSignal(f, lenght);
  //int // <editor-fold defaultstate="collapsed" desc="comment">
  //writeData2File// </editor-fold>
  writeData2File("EKG3.csv", f, lenght);
  system("python3 plotdata.py EKG1.csv EKG3.csv");
 
  return 0;
}