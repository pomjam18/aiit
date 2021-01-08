#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MDATA_MAX_SIZE   1000
#define MOVINGAVERAGING_WINDOW_SIZE   10
#define NO_ERROR 0
#define OUT_OF_MEMORY_ERROR 1
#define FILE_ERROR 2
#define Fenster 4
#define ECGDATA_SAMPLE_RATE 360

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

int findRPeak(double f_2diff[], double f_orig[], int length, double rpeak[], int rpeak_length) 
{

    int nz_legnth = 0;
    int qrs_complex_start = -1, qrs_complex_end = -1;
    int rpeak_i = 0;
    int x = 0;

   //Abtastrate: ECGDATA_SAMPLE_RATE = 360 Hz

    //Abtastdauer: 1/360 s

    //Wieviele Feldelemente sind in 0.6 s enthalten?

    //0.6/(1/360) = 0.6 s * Abtastfrequenz

    const int nsep = 0.6 * ECGDATA_SAMPLE_RATE;

    //1.) Wir suchen den Startpunkt des ersten QRS-Komplexe -> Q-Wert

    for( int i = 0; i < length; ++i) {

        if (f_2diff[i] != 0) {

            qrs_complex_start = i;
            qrs_complex_end = i;
            break;
        }
    }

    //2.) Suche die Start und Endwerte aller restlichen QRS-suchen und zwischen den Start-
    // und Endpunkten wird das Maximum und somit die R-Zacke bestimmt!

    for( int i = qrs_complex_start + 1; i < length; ++i) {

        if (f_2diff[i] != 0) { //Start oder Ende eines QRS-Komplex detektiert?

            if ( (i - qrs_complex_end) >= nsep ) { //neuen QRS-Komplex gefunden!

                if (rpeak_i < rpeak_length) {
                  
                   getMaxValue(&f_orig[qrs_complex_start], qrs_complex_end - qrs_complex_start, &x);
                   rpeak[rpeak_i] = x + qrs_complex_start;

                    //printf("%d.): qrs-start: %d, qrs-length: %d, r-peak: %1.f\n", rpeak_i, qrs_complex_start, qrs_complex_end - qrs_complex_start, rpeak[rpeak_i]);

                    ++rpeak_i;
                    qrs_complex_start = i;
                }
                else {
                    break;
                }
            }
            qrs_complex_end = i;
        }
    }
    /*
     * continue; 
    if (letztes Feldelement - qrs_complex_start > 2*letzterDetektierterHerzschlag)
        ; //-> Stromschlag
    
    */
    
    if (qrs_complex_end > qrs_complex_start) 
    {

        getMaxValue(&f_orig[qrs_complex_start], qrs_complex_end - qrs_complex_start, &x);
       
        rpeak[rpeak_i] = x + qrs_complex_start;
        //printf("%d.): qrs-start: %d, qrs-length: %d, r-peak: %1.f\n", rpeak_i, qrs_complex_start, qrs_complex_end - qrs_complex_start, rpeak[rpeak_i]);
       
        ++rpeak_i;
    }
    return rpeak_i;
}

void printHeartRate(double rpeak[], int length, double f_rpm[]) 
{
  
  int anzahl;
  
  for(int i = 0; i < (length - 1); i++) 
  {
    anzahl = rpeak[i + 1] - rpeak[i];
   
   f_rpm[i] = (ECGDATA_SAMPLE_RATE * 60) /anzahl;
  }
    
}

 
int changeFeld(double f[], double f_orgin[], int length) 
{
  
  for (int i = 0; i < length; i++) {
    f_orgin[i] = f[i];
  }
  return 0;
}

void analyseECG()
{
    const int ecg_timeout = ECGDATA_TIMEOUT * ECGDATA_SAMPLE_RATE;

    static int offset = 0;
    static double ecg[ECGDATA_BUFFERSIZE]; //measurement data

    double ecg_compute[ECGDATA_BUFFERSIZE];
    double rpeak[ECGDATA_BUFFERSIZE];
    double rpeaksignal[ECGDATA_BUFFERSIZE];
    int ecg_length = 0;
    int rpeak_length = 0;

    while(1)
    {

        //1.) Alte bereits analysiert Daten aus dem Messdaten-Buffer löschen
        //2.) Warten bis Datei ECGDATA_FILENAME vom Simulator erstellt wurde und danach in den Buffer einelesen. Benutzen Sie dazu die Funktion readECG
        //3.) QRS-Komplexe detektieren und Herfrequenzen berechen
        //4.) Wenn keine Pulse gefünden wurden Schock abgeben (Ausganbe des Textes Schock in der Konsole)
        //5.) Aktuell berechnete Herzfrequenzen in der Konsole ausgeben
        //6.) Gelesene Datei löschen benutzen Sie daz den Befehl remove. Der Simulator erstellt dann eine neue Datei mit Messdaten.
        //Testen Sie mit dem Simulator einen Hersstillstand
    }
}

int main ()
{
  double f[999];
  int lenght = 999;
  double rpeak[10];
  int rpeak_length = 10; 
  
  
  readDataFromFile("mdata.csv", f, lenght, &lenght);
  writeData2File("EKG1.csv", f, lenght);
  double offset = removeOffset(f, lenght);
  calcMovingAveraging(f, lenght);
  changeFeld(f, f_orig, lenght);
  writeData2File("EKG2.csv", f, lenght);
  diffSignal(f, lenght);
  normalizeSignal(f, lenght);
  diffSignal(f, lenght);
  //int // <editor-fold defaultstate="collapsed" desc="comment">
  //writeData2File// </editor-fold>
  writeData2File("EKG3.csv", f, lenght);
  double rpeak_i = findRPeak(f, f_orig, length, rpeak, rpeak_length); 
  printHeartRate(rpeak, length, f_rpm);
  system("python3 plotdata.py EKG3.csv");
 
  return 0;
}