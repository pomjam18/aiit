
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

double gibFkZahlEin(char* txt)
{
    char s[80];
    char n;
    double wert;
    
    do
    {
    printf(" %s: ", txt);
     
    fgets(s, 80, stdin);
    n = sscanf(s, "%lf", &wert);
    } while(n != 1);
    
    return wert;
}

void gibMatrixEin(char name, double* a11, double* a12, double* a21, double* a22)
{
    char kleinbuchstabe;    
    char i[100];
    
    kleinbuchstabe = name - 'A' + 'a';

    printf("Matrix %c\n", name);
    
    sprintf(&i, "%c 11", kleinbuchstabe);
    *a11 = gibFkZahlEin(i);
    sprintf(&i, "%c 12", kleinbuchstabe);
    *a12 = gibFkZahlEin(i);
    sprintf(&i, "%c 21", kleinbuchstabe);
    *a21 = gibFkZahlEin(i);
    sprintf(&i, "%c 22", kleinbuchstabe);
    *a22 = gibFkZahlEin(i);
    
    
    
}

void gibMatrixAus(char name, double a11, double a12, double a21, double a22)
{
    printf("Matrix %c\n", name);
    
    printf("/ \t %10.3lf \t %10.3lf \t\t\\\n", a11, a12);
    printf("\\\t %10.3lf \t %10.3lf \t\t/\n", a21, a22);
        
}

void addiereMatrix(double a11, double a12, double a21, double a22, double b11, double b12, double b21, double b22, double* c11, double* c12, double* c21, double* c22) 
{
    *c11 = a11 + b11;
    *c12 = a12 + b12;
    *c21 = a21 + b21;
    *c22 = a22 + b22;
    
}

void subtrahiereMatrix(double a11, double a12, double a21, double a22, double b11, double b12, double b21, double b22, double* c11, double* c12, double* c21, double* c22)
{
    *c11 = a11 - b11;
    *c12 = a12 - b12;
    *c21 = a21 - b21;
    *c22 = a22 - b22;
    
}

void multipliziereMatrixMitSkalar(double* a11, double* a12, double* a21, double* a22, double skalar)
{
 *a11 = *a11 * skalar;   
 *a12 = *a12 * skalar;   
 *a21 = *a21 * skalar;
 *a22 = *a22 * skalar;
 
}

void multipliziereMatrizen(double a11, double a12, double a21, double a22,double b11, double b12, double b21, double b22,double* c11, double* c12, double* c21, double* c22)
{
   *c11 = a11 * b11 + a12 * b21;
   *c12 = a11 * b12 + a12 * b22;
   *c21 = a21 * b11 + a22 * b21;
   *c22 = a21 * b12 + a22 * b22;
    
}

void loescheBildschirm()
{
  system("clear"); 
}

void warteAufEnterTaste()
{
  char s[4]; printf("Bitte ENTER Taste drücken!"); 
  fgets(s,4,stdin); 
  fflush(stdin);
}


int main () 
{
    double a11;
    double a12;
    double a21;
    double a22;
    double b11;
    double b12;
    double b21;
    double b22;
    double c11;
    double c12;
    double c21;
    double c22; 
     
    gibMatrixEin('A', &a11, &a12, &a21, &a22);
    
    gibMatrixEin('B', &b11, &b12, &b21, &b22);
    addiereMatrix(a11, a12, a21, a22, b11, b12, b21, b22, &c11, &c12, &c21, &c22);
    gibMatrixAus('C', c11, c12, c21, c22);
    
    return 0;
}

