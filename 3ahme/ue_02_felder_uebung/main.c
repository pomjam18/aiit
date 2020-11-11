
#include <stdio.h>
#include <stdlib.h>


int gibGanzeZahlEin(char* txt)
{
    int zahl = 0;
    char s[40];
    
    printf("%s:", txt);
    
    do
    {
    fgets    (s,40,stdin);
    fflush(stdin);
    fflush(stdin);
        
    }
    while (sscanf(s, "%d", &zahl) !=1);
    
    return zahl;
}


int main (int argc, char** argv) {

    
    
    
    return (EXIT_SUCCESS);
}

