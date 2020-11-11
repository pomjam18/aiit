
#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int main () {

    double f[999];
    double f1[999];
    double summe = 0;
    int n = 10;
    int j = 0;
    
    for(int i=0; i < 1000; i++) {
        
        f[i] = sin(((2 * M_PI) / 100) * i);
    }
    
    for(int i < 1000; i++) {
        
        for(j <= n; j++){
            
           f1[i] = f1[i] + f[j];
        }
        
     j++;
     n++;
    
    }
    
    return 0;
}

