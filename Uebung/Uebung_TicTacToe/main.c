#include <stdio.h>
#include <stdlib.h>


int eingabe(char *txt)
{
    int n = 0; 
    char s[80];
    int eingabe;
    
    do
    {
    printf(" %s ", txt);
    fgets(s, 80, stdin);
    n = sscanf(s, "%d", &eingabe);
    }while(n = 0 || eingabe < 1 || eingabe > 9);
    
    return eingabe;    
}

int randzahl()
{
    int rv = 0;
    
    do
    {
    rv = rand()% (9) + 1;
    }while(rv = 0);
    
    return rv; 
}

void loescheBildschirm()
{
  system("clear"); 
}




int main ()
{
    srand(time(NULL));
    
    int wahl = 0;
    int f[9];
    
    f[0] = 1;
    f[1] = 3;
    
    
    printf("\n\tT i c - T a c - T o e\n"
            "\t---------------------");
    
    
    printf("\n\n\tSpielen ....1\n"
            "\tBeenden ....9\n");
   do
   {
       wahl = eingabe("\n\tIhre Wahl:");
   }while(wahl != 1 && wahl != 9);
   
   loescheBildschirm();
   
   switch(wahl)
   {
   
       case 1:
           printf(" \n");
           
           for(int i = 0; i < 11; i++)
           {
               if(i = 1)
               {
                 for(int j = 0; j < 9; j++)  
                 {
                     if(f[j] == 1)
                     printf("\t X |");
                 else
                     printf("\t   |");
                 if(f[j] == 2)
                     printf(" X |");
                 else
                     printf("   |");
                 if(f[j] == 3)
                     printf(" X ");
                 else 
                     printf("   ");
                 }
                 
           }
               
            if(i == 3 || i == 7)
               printf("\t    -------------\n");
           else
           printf("\t\t|   |\t\n");    
           }
                  
    
    
    
       case 9:
           return 0;
   } 
    
    return 0;
}

