/* 
 * File:   main.c
 * Author: jan
 *
 * Created on 30. November 2020, 16:25
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>


void findeprimzahl(int *i, int x) {

  // int x, i;
    
   for (x = 2; x <= 100; x++)
    {

        for (*i = 2;*i <= x; *i++)
        {
        if (x%*i == 0 && x != i) break; 

        if (*i == x) 
            return *i;

        }
    }
}
int main () {

       int x, i, anzahl;
    for (x = 2; x <= 1000000; x++)
    {

        for (i = 2; i <= x; i++)
        {
        if (x%i == 0 && x != i) break; 

        if (i == x) anzahl++;

}

    }
       printf("%i",anzahl);
    return 0;
        
/*  
    int anzahl = 0;
    bool primzahl = true;
    
    for(int i = 2; i < 100; i++)
    {
        
       for(int j = 2; j <= i; j++)
       {
           
           if(j%i == 0) 
           {
               primzahl = false;
               break;
           }
           
       }
       if(primzahl = true)
           anzahl++;
       

    }
    printf("%i", anzahl);
    
  */  
    return 0;
    
    
    return (EXIT_SUCCESS);
}

