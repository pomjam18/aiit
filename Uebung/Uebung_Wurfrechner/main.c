
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


double eingabe(char *txt)
{
    double wert;
    
    printf("%s", txt);
    sscanf("%lf", &wert);    
    
    return wert;
}

double berechneSWh(double a, double v)
{
    double q = 2;
    
    double h = (pow((v * sin(a)),q) / (2 * 9.81) );
    
    return h;    
}

double berechneSWsx(double a, double v)
{
    double q = 2;
    
    double w = ((pow(v ,q) * sin(2 * a)) / ( 9.81) );
    
    return w;    
}

double berechneSWt(double a, double v)
{
       
    double t = ((v * sin(a)) / ( 9.81) );
    
    return t;    
}

double berechneWWsx(double v, double h)
{
    double sx;
    
    sx = v * sqrt((2 + h) / 9.81);
            
    return sx;
}

double berechneWWh(double sx, double v)
{
      double q = 2;
      double h;
      
    h = 0.5 * 9.81 * pow((sx / v), q);
    
    return h;
}

double berechneWWt(double h)
{
    double t;
    
    t = sqrt((2 * h) / 9.81);
    
    return t;
}

double berechneFFv(double s)
{
    
   double v = sqrt(2 * 9.81 * s); 
    
   return v;
}

double berechneFFt(double s)
{
    
   double t = sqrt((2 * s) / 9.81); 
    
   return t;
}

double berechneFFs(double t)
{
    double q = 2;
   
    double s = 0.5 * 9.81 * pow(t, q); 
    
   return s;
}

void wahl(int *x)
{
 
    switch(*x)
    {
        case 1:
            
         printf("\n\t S C H R Ä G E R - W U R F\n");   
         printf("\nGesucht:");
         printf("\nWurfhöhe....1"
                "\nWurfweite...2"
                "\nWurfdauer...3");
            
         int y = eingabe("Wahl:");
         
         switch(y)
         {
             case 1:
                            
              double v = eingabe("\nAnfangsgeschwindigkeit:"); 
              double a = eingabe("\nAbschusswinkel:");
                
              double sx = berechneSWh(double a, double v); 
                      
              printf("\nWurfhöhe: %lf",sx);       
                 
                 break;
             case 2:
              
              double v = eingabe("\nAnfangsgeschwindigkeit:"); 
              double a = eingabe("\nAbschusswinkel:");
                
              double sx = berechneSWsx(double a, double v); 
                      
              printf("\nWurfweite: %lf",sx);       
                   
                 
              break;
             case 3:
                 
              double v = eingabe("\nAnfangsgeschwindigkeit:"); 
              double a = eingabe("\nAbschusswinkel:");
                
              double sx = berechneSWt(double a, double v); 
                      
              printf("\nWurfdauer: %lf",sx);   
              
              break;
                 
                 
         }        
            
            
        case 2:
            
         printf("\n\t W A A G R E C H T E R - W U R F\n");   
         printf("\nGesucht:");
         printf("\nWurfweite....1"
                "\nWurfhöhe.....2"
                "\nWurfdauer....3\n");
            
         int z = eingabe("Wahl:");
         
         switch(z)
         {
            case 1:
            
              double v = eingabe("\nAnfangsgeschwindigkeit:"); 
              double h = eingabe("\nHöhe:");
                
              double sx = berechneWWsx(double v, double h); 
                      
              printf("Wurfweite: %lf",sx);        
                
            break;
             case 2:
                 
             double sx = eingabe("\nWurfweite:");
             double v = eingabe("\nAnfangsgeschwindigkeit:"); 
       
             double h = berechneWWh(double sx, double v);   
                 
             printf("\nHöhe: %lf",h);
             
            break;
             
             case 3:
                
             double h = eingabe("\nHöhe::");
          
       
             double t = berechneWWt(double h);   
                 
             printf("\nDauer: %lf",t);   
                 
             break;    
                 
         }         
                 
            
        case 3:
        
        printf("\n\tF R E I E R - F A L L\n");   
         printf("\nGesucht:");
         printf("\nGeschwindigkeit.....1"
                "\nFalldauer...........2"
                "\nFallstrecke.........3");
            
         int n = eingabe("Wahl:");
         
         switch(n)
         {
             case 1:
              
            double s = eingabe("\nFallstrecke:");
             
                            
             double v = berechneFFv(double s);    
                 
             printf("\nGeschwindigkeit: %lf", v);
             
             break;
             case 2:
                 
             double s = eingabe("\nFallstrecke:");
             
                            
             double t = berechneFFt(double s);    
                 
             printf("\nFalldauer: %lf", t);    
                 
              break;   
              case 3:
              
              double t = eingabe("\nFalldauer:");
             
                            
             double s = berechneFFs(double t);    
                 
             printf("\nFallstrecke: %lf", s);    
                 
              break;   
                 
                 
         }     
            
            
        case 9:
            break;
            
    }
    
}



int main ()
{

    printf("\n\tB E W E G U N G S R E C H N E R \n");
    printf("\n Welche Rechenoperation möchten Sie durchführen:\n");
    printf("\n Schräger Wurf ........1\n"
             " Waagrechter Wurf .....2\n"
             " Freier Fall ..........3\n"
             " Programm Beenden .....9\n");
    
    int x = eingabe("Ihre Wahl: ");
    
    wahl(x);
    
    
    return 0;
}

