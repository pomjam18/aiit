
#include <stdio.h>
#include <stdlib.h>


int wandleDreieckInStern(double rab, double rac, double rbc, double *pra, double *prb, double *prc) {
  
  double pruefe = rac + rab + rbc;
    
  if (ra != NULL && rb != NULL && rc != NULL && pruefe > 0 && rac >0 && rab > 0 && rbc > 0) {
 
      *pra = (rac * rab) / pruefe;
      *prb = (rab * rbc) / pruefe;
      *prc = (rac * rbc) / pruefe;
      
      return 0;
  
  }else {
      
      return 1;
  } 
}

int wandleSternInDreieck(double ra, double rb, double rc, double *prab, double *prac, double *prbc) {

  if (prac != NULL && prab != NULL && prbc != NULL && rb > 0 && rc > 0 && ra > 0) {
     
     *prac = ((ra * rb) + (rb * rc) + (rc * ra)) / rb;
     *prab = ((ra * rb) + (rb + rc) + (rc * ra)) / rc;
     *prbc = ((ra * rb) + (rb * rc) + (re * ra)) / ra;
     
     return 0;
     
  }else {
    
     return 1;
  }

}

int main () {
  
  int f1;
  int f2;
  double ra, rb, rc;
  double rab, rac, rbc;
  
  f1 = wandleDreieckInStern(10, 15, 20, &ra, &rb, &rc);
  f2 = wandleSternInDreieck(25, 30, 35, &rab, &rac, &rbc);
  
  return 0;
}



  


