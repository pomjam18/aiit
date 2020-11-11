
#include <stdio.h>
#include <stdlib.h>

int gibZahlenEin(double f[]) {
    
    char s[100];
    double wert;
    int z = 1;
    int i = 0;
    
    do { 
        do {
            printf("Gib bitte eine Zahl ein: %d ", z);
            fgets(s, 100, stdin);
            fflush(stdin);
        } while (sscanf(s,"%lf", &wert) < 1); 
        
        if ( wert >= 0 )
        { 
            f[i] = wert;
            i++;
        }  
        
    } while (i > 1000 && wert > 0);
        
    return i;  
}

 double berechneMittelwert(double f[], int anzahl) {
     double av;
     double summe1 = 0;
     double summe2 = 0;
     double t = 0;
     
     for(int i; i <= anzahl; i++) {
         f[i] = t;
         summe2 = summe1 + t;
         summe1 = summe2;
     }     
     
     av = summe2 / anzahl;
     
     return av;
 }

 double berechneStdAbw(double f[], int anzahl, double av) {
     double t = 0;
     double abw = 0;
     
     
     for(int i = 0; i <= anzahl; i++) {
         t = t + ((f[i] - av) ^ 2);
         abw = sqrt(t / anzahl);
         
         return abw;
     }    
 }
 
     
int main () {
    double f[999];
    int anzahl;
    double t;
    double abw,
            
     
        printf("/t UE_04 Statische Berechnungen:/n");    
        printf("Gib Zahlen ein aus denen der Mittelwert und die Standard-Abweichung berechnet wird{n:");
        
        anzahl = gibZahlenEin(i);
        abw = berechneStdAbw(abw);
        
        gibZahlenEin(i);
         
       printf("Standartabweichung: %lf", abw);
        
       
    
    
    return 0;
}

