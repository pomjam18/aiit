#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int anzahl = 12;
int maxchar = 50;

/* 
char erzeugezufallschar()
{
    char randomletter = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"[random () % 26];
    
    return randomletter;
}



void namenfeldgenerieren(char namensliste[][maxchar])
{
 int laengename = rand () % 16 + 5;   
 
 for(int i = 0; i < anzahl; i++)
 {
     for(int j = 0; j < laengename; j++)
     {
         namensliste[i][j] = erzeugezufallschar;
     }
 }
}
*/


void ausgabe(char namensliste[][maxchar]) {
  
  int i;     
  for(i = 0; i < anzahl; i++) {
    
    printf("%s\n", namensliste[i]);
  }
  
}

void bubblesort(char namensliste[][maxchar]){
  char tmp[maxchar];
  
  for(int i  = 0; i < anzahl - 1; i++){
    for(int j = 0; j < anzahl - 1 - i; j++){
      if(strcmp(namensliste[j], namensliste[j + 1]) > 0) {
        
        strcpy(tmp, namensliste[j]);
        strcpy(namensliste[j], namensliste[j + 1]);
        strcpy(namensliste[j + 1], tmp);
      }
    } 
  }
}


int main ()
{
  
    printf("\t N A M E N  S O R T I E R E N\n"
            "\t------------------------------\n\n");
    
    
  //habe versucht in Zeile 44 "namensliste[anzahl][maxchar]" zu schreiben, funktioniert aber irgendwie nicht
  
  char namensliste[12][50] = {"Oliver", "Jakob Kurzmann", "Jakob Rumpf", "Jan", "Fabio", "Sebastian Sever", "Matteo", "Sebastian Pojer", "Elias Hoebel", "Elias Kolb", "Tobias", "Eric" };
  
  printf("\nNicht sortierte Namen: \n\n");
  ausgabe(namensliste);
  
  bubblesort(namensliste);
  printf("\nAlphabetisch sortierte Namen: \n");
  ausgabe(namensliste);
  
  
  /*
  char liste2[12][50];
  namenfeldgenerieren(liste2[12][50]);
  ausgabe(liste2);
  */
  
  return 0;
}