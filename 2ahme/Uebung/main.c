

#include <stdio.h>

int main ()
{

char s [100];
double durchmesser;

printf(" Durchmesser: ");
fgets(s, 100, stdin);
sscanf (s, "%lf", &durchmesser);

double ergebnis =durchmesser/2*durchmesser/2*3.14159265358979323846;
printf(" Fläche = %.2f\n", ergebnis); 



  return 0;
}

