
#include <stdio.h>
#include <stdlib.h>




void loesche_bild()
{
    int x;
    for(x = 1; x <= 25; x++)
    {
        printf("\n");
    }
    
}



int main () 

{

    double x, y, z;
    
    loesche_bild();
    printf("\nBitte x eingeben: ");
    scanf("%lf", &x);
    loesche_bild();
    printf("\nBitte y eingeben: ");
    scanf("%lf", &y);
    loesche_bild();
    printf("\nBitte z eingeben: ");
    scanf("%lf", &z);
    loesche_bild();
    printf("\n%lf + %lf + %lf = %lf\n",x, y, z, x + y + z);
    
    
    return 0;
}

