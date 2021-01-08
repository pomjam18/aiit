

#include <stdio.h>
#include <stdlib.h>


double eingabe(char *txt)
{
    char s[80];
    char n;
    double wert;
    
    do
    {
    printf("%s ", txt);
     
    fgets(s, 80, stdin);
    n = sscanf(s, "%lf", &wert);
    } while(n != 1);
    
    return wert;
}

void loescheBildschirm()
{
  system("clear"); 
}

void warteAufEnterTaste()
{
  char s[4]; printf("\n\nBitte #(ENTER) Taste drücken um ins Auswahlfenster zu gelangen!"); 
  fgets(s,4,stdin); 
  fflush(stdin);
}

void warteAufEnterTaste1()
{
  char s[4]; printf("\n\nBitte #(ENTER) Taste drücken um Automat auszuschalten!"); 
  fgets(s,4,stdin); 
  fflush(stdin);
}

int main () 
{

    printf("\n G E T R Ä N K E A U T O M A T\n");
    printf("\nCola .....1"
           "\nWasser....2"
           "\nFanta.....3"
           "\nRedBull...4"
           "\n\nAutomat ausschalten..9\n");
    
    int x = eingabe("\nIhre Wahl:");
    
    switch(x)
    {
        case 1:
            
          loescheBildschirm();
          
          printf("\n\tC O L A\n");
          printf("\nBitte werfen Sie 2 Euro ein\n");
          
          double wert = eingabe("\nBitte eingeworfenen Betrag eingeben:");
          double soll = wert;
          
          if(wert < 2)
          {
              printf("\nEs wurde zu wenig Geld eingeworfen!");
          do{
              loescheBildschirm();
              printf("\n\nEs fehlen noch %.2lf€\n", 2 - soll);
              wert = eingabe("\nBitte fehlenden Betrag einwerfen:");
              soll = soll + wert;
              loescheBildschirm();
          }while(soll < 2);
           if(soll < 2)
              printf("\nEs wurde zu wenig Geld eingeworfen!");
          
          else if(soll > 2){
              printf("\n%.2lf€ Returgeld\n"
                     "\nGetränk kann entnommen werden!", soll - 2);
          }else 
              printf("\n\nGetränk kann entnommen werden!");      
          }else if(wert > 2){
              printf("\n%.2lf€ Returgeld\n"
                     "\nGetränk kann entnommen werden!", wert - 2);
          }else 
              printf("\n\nGetränk kann entnommen werden!");
             
          
          warteAufEnterTaste();
          loescheBildschirm();
          main();
          break;
          
        case 2:
            
         loescheBildschirm();
          
          printf("\n\tW A S S E R\n");
          printf("\nBitte werfen Sie 0,50 Euro ein\n");
          
          double wert1 = eingabe("\nBitte eingeworfenen Betrag eingeben:");
          double soll1 = wert1;
          
          if(wert1 < 0.5)
          {
              printf("\nEs wurde zu wenig Geld eingeworfen!");
          do{
              printf("\nEs fehlen noch %.2lf€\n", 0.5 - soll1);
              wert1 = eingabe("\nBitte fehlenden Betrag einwerfen:");
              soll1 = soll1 + wert1;
          }while(soll1 < 0.5);
           if(soll1 < 0.5)
              printf("\nEs wurde zu wenig Geld eingeworfen!");
          
          else if(soll1 > 0.5){
              printf("\n%.2lf€ Returgeld\n"
                     "\nGetränk kann entnommen werden!", soll1 - 0.5);
          }else 
              printf("\n\nGetränk kann entnommen werden!");      
          }else if(wert1 > 0.5){
              printf("\n%.2lf€ Returgeld\n"
                     "\nGetränk kann entnommen werden!", wert1 - 0.5);
          }else 
              printf("\n\nGetränk kann entnommen werden!");
             
          
          warteAufEnterTaste();
          loescheBildschirm();
          main();
          break;  
        
        case 3:
          
          loescheBildschirm();
          
           printf("\n\tF A N T A \n");
          printf("\nBitte werfen Sie 2 Euro ein\n");
           
          double wert2 = eingabe("\nBitte eingeworfenen Betrag eingeben:");
          double soll2 = wert2;
           
         
          
           if(wert2 < 2)
          {
              printf("\nEs wurde zu wenig Geld eingeworfen!");
          do{
              printf("\nEs fehlen noch %.2lf€\n", 2 - soll2);
              wert2 = eingabe("\nBitte fehlenden Betrag einwerfen:");
              soll2 = soll2 + wert2;
          }while(soll2 < 2);
           if(soll2 < 2)
              printf("\nEs wurde zu wenig Geld eingeworfen!");
          
          else if(soll2 > 2){
              printf("\n%.2lf€ Returgeld\n"
                     "\nGetränk kann entnommen werden!", soll2 - 2);
          }else 
              printf("\n\nGetränk kann entnommen werden!");      
          }else if(wert2 > 2){
              printf("\n%.2lf€ Returgeld\n"
                     "\nGetränk kann entnommen werden!", wert2 - 2);
          }else 
              printf("\n\nGetränk kann entnommen werden!");
             
          
          warteAufEnterTaste();
          loescheBildschirm();
          main();
          break;  
          
        case 4:
            
            loescheBildschirm();
          
          printf("\n\tR E D B U L L \n");
          printf("\nBitte werfen Sie 2 Euro ein\n");
          
          double wert3 = eingabe("\nBitte eingeworfenen Betrag eingeben:");
          double soll3 = wert3;
          
           if(wert3 < 2)
          {
              printf("\nEs wurde zu wenig Geld eingeworfen!");
          do{
              printf("\nEs fehlen noch %.2lf€\n", 2 - soll3);
              wert3 = eingabe("\nBitte fehlenden Betrag einwerfen:");
              soll3 = soll3 + wert3;
          }while(soll3 < 2);
           if(soll3 < 2)
              printf("\nEs wurde zu wenig Geld eingeworfen!");
          
          else if(soll3 > 2){
              printf("\n%.2lf€ Returgeld\n"
                     "\nGetränk kann entnommen werden!", soll3 - 2);
          }else 
              printf("\n\nGetränk kann entnommen werden!");      
          }else if(wert3 > 2){
              printf("\n%.2lf€ Returgeld\n"
                     "\nGetränk kann entnommen werden!", wert3 - 2);
          }else 
              printf("\n\nGetränk kann entnommen werden!");
             
          
          warteAufEnterTaste();
          loescheBildschirm();
          main();
          break; 
        
        case 9:
            loescheBildschirm();
            
            int wert4 = eingabe("\nBitte Code eingeben:");
            
            if(wert4 < 2412 || wert4 > 2412)
            {
                wert4 = 1;
            }else
            {
                wert4 = 2;
            }
            switch(wert4)
            {
                case 1:
                    printf("Falscher Code!\n");
                    warteAufEnterTaste();
                    loescheBildschirm();
                    main();
                break;
                
                case 2:
                    
                 printf("Automat kann ausgeschalten werden!\n"); 
                 warteAufEnterTaste1();
                 break;
                    
                    
            }
            
            break;
          
    }
    
    
   
    return 0;
}

