#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int wandleDreieckInStern (double rab, double rac, double rbc, double *pRa, double *pRb, double *pRc) {
  
 double pruefe = rac + rab + rbc;
  
  if (pRa != NULL && pRb != NULL && pRc != NULL && pruefe > 0 && rac > 0 && rab > 0 && rbc > 0) {
    
    *pRa = (rac * rab) / (rac + rab + rbc);
    *pRb = (rab * rbc) / (rac + rab + rbc);
    *pRc = (rac * rbc) / (rac + rab + rbc);
    
    return 0;
  } else {
    return 1;
  }
}

int wandleSternInDreieck (double ra, double rb, double rc, double *pRab, double *pRac, double *pRbc) {
  
  if (pRab != NULL && pRac != NULL && pRbc != NULL && ra > 0 && rb > 0 && rc > 0) {
    
    *pRac = (ra * rb + rb * rc + rc * ra) / rb;
    *pRab = (ra * rb + rb * rc + rc * ra) / rc;
    *pRbc = (ra * rb + rb * rc + rc * ra) / ra;
    
    return 0;
  } else {
    return 1; 
  } 
}

int testDreieckInStern () {
 int rv;
 double rab, rac,rbc, ra, rb, rc;
  
 rab = 1; rac = 2; rbc = 3;
 
  while (rab <= 2) {  
 
    rv = wandleDreieckInStern(rab, rac, rbc, &ra, &rb, &rc);    
    double raT = (rac * rab) / (rac + rab + rbc);
    double rbT = (rab * rbc) / (rac + rab + rbc);
    double rcT = (rac * rbc) / (rac + rab + rbc);
  
    const double eps = 1E-10;
    
  if (abs (ra - raT && rb - rbT && rc - rcT) <= eps) {
    printf("Test 1a erfolgreich ");
  } else {
    printf("Fehler ");
  }

  if (rv != 0) {
    printf("Test 1: Fehler rv = %d\n", rv);
  } else {
    printf("rab=%lf, rac=%lf, rbc=%lf -> ra=%lf, rb=%lf, rc=%lf\n",
    rab, rac, rbc, ra, rb, rc);
  }
 rab++;
  }
 return rv;
}

int testSternInDreieck () {
 int rv;
 double  ra, rb, rc, rab, rbc, rac, eps;
  
 ra = 1; rb = 2; rc = 3;
 
 while (ra <= 2) {
  rv = wandleSternInDreieck(ra, rb, rc, &rab, &rbc, &rac);
  
  double racT = (ra * rb + rb * rc + rc * ra) / rb;
  double rabT = (ra * rb + rb * rc + rc * ra) / rc;
  double rbcT = (ra * rb + rb * rc + rc * ra) / ra;
 	
 if (abs (rac - racT && rab - rabT && rbc - rbcT) <= eps) {
   printf("Test 1b erfolgreich ");
 } else {
   printf("Fehler ");
 }
  	
 if (rv != 0) {
   printf("Test 1: Fehler rv = %d\n", rv);
 } else {
    
   printf("rab=%lf, rac=%lf, rbc=%lf -> ra=%lf, rb=%lf, rc=%lf\n",
   rab, rac, rbc, ra, rb, rc);
 }
ra++;
 }
return rv;
}

int testNULL () {
 int rv = 0;
 double ra, rb, rc, rab, rac, rbc;
  
 int rv1 = wandleSternInDreieck(1, 2, 3, NULL, &rbc, &rac);
 int rv2 = wandleSternInDreieck(1, 2, 3, &rab, NULL, &rac);
 int rv3 = wandleSternInDreieck(1, 2, 3, &rab, &rbc, NULL);
 int rv4 = wandleDreieckInStern(1, 2, 3, NULL, &rb, &rc);
 int rv5 = wandleDreieckInStern(1, 2, 3, &ra, NULL, &rc);
 int rv6 = wandleDreieckInStern(1, 2, 3, &ra, &rb, NULL);
  
  if (rv1 && rv2 && rv3 && rv4 && rv5 && rv6 == 1) {
    printf("Test 2  erfolgreich\n");
  } else {
    printf("rv1=%d, rv2=%d, rv3=%d, rv4=%d, rv5=%d, rv6=%d\n", rv1, rv2, rv3, rv4, rv5, rv6); 
  }
return rv;
}

int wertparameterGleichNull () {
 int rv;
 double ra, rb, rc, rab, rac, rbc;
 int rv1 = wandleSternInDreieck(0, 2, 3, &rab, &rbc, &rac);
 int rv2 = wandleSternInDreieck(1, 0, 3, &rab, &rbc, &rac);
 int rv3 = wandleSternInDreieck(1, 2, 0, &rab, &rbc, &rac);
 int rv4 = wandleDreieckInStern(0, 2, 3, &ra, &rb, &rc);
 int rv5 = wandleDreieckInStern(1, 0, 3, &ra, &rb, &rc);
 int rv6 = wandleDreieckInStern(1, 2, 0, &ra, &rb, &rc);
  
  if(rv1 && rv2 && rv3 && rv4 && rv5 && rv6 == 1) {
    printf("Test 3  erfolgreich\n");  
  } else {
    printf("rv1=%d, rv2=%d, rv3=%d, rv4=%d, rv5=%d, rv6=%d\n", rv1, rv2, rv3, rv4, rv5, rv6); 
  }
 return rv;
}


int main () {
  
// Test 1a: wandleDreieckInStern
 int funktion1 = testDreieckInStern();
 
 // Test 1b: wandleSternInDreieck
 int funktion2 = testSternInDreieck();

 // Test 2: rab, rac, rbc, ra, rb, rc gleich NULL
 int funktion3 = testNULL();

 // Test 3: Wertparameter <= 0 
 int funktion4 = wertparameterGleichNull();

}

//return 0;