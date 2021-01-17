
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
    printf("%s: ", txt);
     
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

    printf("\nMatrix %c\n", name);
    
    sprintf(&i, "%c11", kleinbuchstabe);
    *a11 = gibFkZahlEin(i);
    sprintf(&i, "%c12", kleinbuchstabe);
    *a12 = gibFkZahlEin(i);
    sprintf(&i, "%c21", kleinbuchstabe);
    *a21 = gibFkZahlEin(i);
    sprintf(&i, "%c22", kleinbuchstabe);
    *a22 = gibFkZahlEin(i);
    
    
    
}

void gibMatrixAus(char name, double a11, double a12, double a21, double a22)
{
    printf("\nMatrix %c\n", name);
    
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

double berechneDeterminante(double a11, double a12, double a21, double a22)
{
    double det = 0;
    
    det = a11 * a22 - a12 * a21;
    
    //printf("def: %lf\n", det); zu testzwecken
    
    return det;
}

int invertiereMatrix(double* a11, double* a12, double* a21, double* a22)
{
  double det = berechneDeterminante(*a11, *a12, *a21, *a22);
    
  double temp = *a11;
  
  if(det == 0)
  {  
      return 1;
  }else
  {
  *a11 = (1 / det) * *a22;
  *a12 = (1 / det) * (-*a12);
  *a21 = (1 / det) * (-*a21);
  *a22 = (1 / det) * temp;  
  }
    
  if(det =! 0) 
      return 0;
  else
      return 1;
  }


 int dividiereMatrizen(double a11, double a12, double a21, double a22, double b11, double b12, double b21, double b22, double* c11, double* c12, double* c21, double* c22)
{
   int pruefe = invertiereMatrix(&b11, &b12, &b21, &b22);
   
   if(pruefe == 0)
   {
      multipliziereMatrizen(a11, a12, a21 ,a22, b11, b12, b21, b22, &*c11, &*c12, &*c21, &*c22);
   }else
       return 0;
   
   
   
}


 

void loescheBildschirm()
{
  system("clear"); 
}

void warteAufEnterTaste()
{
  char s[4]; printf("\nBitte ENTER Taste drücken!"); 
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
    int eingabe;
     
    printf("Rechnen mit 2x2 Matrizen\n"
           "========================\n");
    
    printf("\nAddition zweier Matrizen .................................1\n"
           "Subtraktion zweier Matrizen ..............................2\n"
           "Multiplikation zweier Matrizen ...........................3\n"
           "Determinante berechnen ...................................4\n"
           "Matrix invertieren .......................................5\n"
           "Matrizen dividieren ......................................6\n"
           "Programmende .............................................9\n\n");
    
       
    eingabe = gibFkZahlEin("Ihre Wahl"); 
    
    loescheBildschirm(); 
    
    
    switch(eingabe)
    {
    case 1:
        
    printf("Addition zweier Matrizen\n");
                   
    gibMatrixEin('A', &a11, &a12, &a21, &a22);
    
    gibMatrixEin('B', &b11, &b12, &b21, &b22);
    addiereMatrix(a11, a12, a21, a22, b11, b12, b21, b22, &c11, &c12, &c21, &c22);
    gibMatrixAus('C', c11, c12, c21, c22);
    
    warteAufEnterTaste();
    loescheBildschirm();
    
    main();
    
    break;
    
    case 2:
    
    printf("Subtraktion zweier Matrizen\n");    
        
    gibMatrixEin('A', &a11, &a12, &a21, &a22);
    
    gibMatrixEin('B', &b11, &b12, &b21, &b22);
    subtrahiereMatrix(a11, a12, a21, a22, b11, b12, b21, b22, &c11, &c12, &c21, &c22);
    gibMatrixAus('C', c11, c12, c21, c22);    
    
    warteAufEnterTaste();
    loescheBildschirm();
             
    main();
    
    break;

    case 3:
        
    printf("Multiplikation zweier Matrizen\n");    
        
    gibMatrixEin('A', &a11, &a12, &a21, &a22);
    
    gibMatrixEin('B', &b11, &b12, &b21, &b22);
    multipliziereMatrizen(a11, a12, a21, a22, b11, b12, b21, b22, &c11, &c12, &c21, &c22);
    gibMatrixAus('C', c11, c12, c21, c22);      
    
    warteAufEnterTaste();
    loescheBildschirm();    
    
    main();
     
    break;
    
    case 4:
        
    printf("Determinante berechnen\n");    
        
    gibMatrixEin('A', &a11, &a12, &a21, &a22);
    
    double def = berechneDeterminante(a11, a12, a21, a22);
    
    printf("\nDeterminate = %lf\n", def);
    
    warteAufEnterTaste();
    loescheBildschirm();    
    
    main();
     
    break;
    
     case 5:
        
    printf("Matrix invertieren\n");    
        
    gibMatrixEin('A', &a11, &a12, &a21, &a22);
    
    //invertiereMatrix(&a11, &a12, &a21, &a22);
    
    if(invertiereMatrix(&a11, &a12, &a21, &a22) != 0) {
        printf("\nNicht Möglich\n");
    } else {
      gibMatrixAus('A', a11, a12, a21, a22);   
    }
       
    
    warteAufEnterTaste();
    loescheBildschirm();    
    
    main();
     
    break;
    
    case 6:
        
    printf("Matrizen dividieren\n");    
        
    gibMatrixEin('A', &a11, &a12, &a21, &a22);
    gibMatrixEin('B', &b11, &b12, &b21, &b22);
    
    if(dividiereMatrizen(a11, a12, a21, a22, b11, b12, b21, b22, &c11, &c12, &c21, &c22) == 0) {
        printf("\nNicht Möglich\n");
    } else{
         gibMatrixAus('C', c11, c12, c21, c22); 
    }
         
    warteAufEnterTaste();
    loescheBildschirm();    
    
    main();
     
    break;
    
    case 9:
        
        printf("Programm beendet!");
        
    break;    
    }
    
    return 0;
}

