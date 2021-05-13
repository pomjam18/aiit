/* 
 * File:   main.c
 * Author: jan
 *
 * Created on 29. April 2021, 14:15
 */

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

int main () 
{

    //Datei anlegen  ->  fopen
    int jahr = 2021, monat = 05, tag = 5;
    
    FILE *f = fopen("test.txt", "w");
    if(f == NULL) // Datei konnte nicht geöffnet werden
    {
        printf("Fehler aufgetreten (Fehler %d)\n", errno);
        printf("-> %s\n", strerror(errno));
    }
    fputs("Moin!\n", f);
    int rv = fputs("Mahlzeit!\n", f);
    rv = fprintf(f, "%d;%d;%d\n", jahr, monat, tag);
    strtok;
    char s[80];
    
    //fputs(s,f);
    //fgets(...)
    
    if(rv == EOF)
        printf("Fehler");
    
    
    if(fclose(f) == EOF)
    {
        printf("Datei konnte nicht geschlossen werden");
    }
    char test[80];
    f = fopen("test.txt","r");
    
    if(f == NULL)
        return 0;
    
    while(fgets(s, sizeof(s), f) != NULL)
    {
        //s = 2021;5;5\n
      if  (sscanf(s,"%[^;]%d;%d;%d", test, &jahr, &monat, &tag) != 4)
      {
          printf("Fehler Text konnte nicht konvertiert werden\n");
          printf("Text: %s \n", s);
      }
    
      //Variante 2 mit strtok
      char *p = strtok(s,";");
      
      strtok(NULL,";");
      return 0;
      strcpy(test, p);
      
      p = strtok(NULL, ";");
      if (p == NULL)
          break;
      sscanf("%d", &jahr);
      
      p = strtok(NULL, ";");
      if (p == NULL)
          break;
      sscanf("%d", &monat);}
      
      p = strtok(NULL, ";");
      if (p == NULL)
          break;
      sscanf("%d", &tag);
      
      }
      fclose(f);
    printf("%d;%d;%d", jahr, monat, tag);
    
    //Test  1;2021;05;06\n
   
  
    
    
    
    
    
    
    
    return 0;
}


